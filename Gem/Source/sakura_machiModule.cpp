
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "sakura_machiSystemComponent.h"

namespace sakura_machi
{
    class sakura_machiModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(sakura_machiModule, "{CC24CC3A-7343-42AB-8B3E-EB25A5316385}", AZ::Module);
        AZ_CLASS_ALLOCATOR(sakura_machiModule, AZ::SystemAllocator, 0);

        sakura_machiModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                sakura_machiSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<sakura_machiSystemComponent>(),
            };
        }
    };
}// namespace sakura_machi

AZ_DECLARE_MODULE_CLASS(Gem_sakura_machi, sakura_machi::sakura_machiModule)
