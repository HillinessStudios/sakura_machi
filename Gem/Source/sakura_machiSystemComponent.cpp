
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "sakura_machiSystemComponent.h"

namespace sakura_machi
{
    void sakura_machiSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<sakura_machiSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<sakura_machiSystemComponent>("sakura_machi", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void sakura_machiSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("sakura_machiService"));
    }

    void sakura_machiSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("sakura_machiService"));
    }

    void sakura_machiSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void sakura_machiSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    sakura_machiSystemComponent::sakura_machiSystemComponent()
    {
        if (sakura_machiInterface::Get() == nullptr)
        {
            sakura_machiInterface::Register(this);
        }
    }

    sakura_machiSystemComponent::~sakura_machiSystemComponent()
    {
        if (sakura_machiInterface::Get() == this)
        {
            sakura_machiInterface::Unregister(this);
        }
    }

    void sakura_machiSystemComponent::Init()
    {
    }

    void sakura_machiSystemComponent::Activate()
    {
        sakura_machiRequestBus::Handler::BusConnect();
    }

    void sakura_machiSystemComponent::Deactivate()
    {
        sakura_machiRequestBus::Handler::BusDisconnect();
    }
}
