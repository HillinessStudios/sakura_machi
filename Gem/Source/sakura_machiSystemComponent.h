
#pragma once

#include <AzCore/Component/Component.h>

#include <sakura_machi/sakura_machiBus.h>

namespace sakura_machi
{
    class sakura_machiSystemComponent
        : public AZ::Component
        , protected sakura_machiRequestBus::Handler
    {
    public:
        AZ_COMPONENT(sakura_machiSystemComponent, "{D5B6390F-7A1C-4355-80C8-6DD4AC2727C1}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        sakura_machiSystemComponent();
        ~sakura_machiSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // sakura_machiRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
