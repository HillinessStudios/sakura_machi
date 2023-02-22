
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace sakura_machi
{
    class sakura_machiRequests
    {
    public:
        AZ_RTTI(sakura_machiRequests, "{FED94C74-6A18-438E-8DC6-145E2743CC48}");
        virtual ~sakura_machiRequests() = default;
        // Put your public methods here
    };

    class sakura_machiBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using sakura_machiRequestBus = AZ::EBus<sakura_machiRequests, sakura_machiBusTraits>;
    using sakura_machiInterface = AZ::Interface<sakura_machiRequests>;

} // namespace sakura_machi
