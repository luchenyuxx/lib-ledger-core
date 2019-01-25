// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#ifndef DJINNI_GENERATED_WALLETPOOLCALLBACK_HPP
#define DJINNI_GENERATED_WALLETPOOLCALLBACK_HPP

#include "../utils/optional.hpp"
#include <memory>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class WalletPool;
struct Error;

/**
 *Callback triggered by main completed task,
 *returns optional result of template type T
 */
class WalletPoolCallback {
public:
    virtual ~WalletPoolCallback() {}

    /**
     * Method triggered when main task complete
     * @params result optional of type T, non null if main task failed
     * @params error optional of type Error, non null if main task succeeded
     */
    virtual void onCallback(const std::shared_ptr<WalletPool> & result, const std::experimental::optional<Error> & error) = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_WALLETPOOLCALLBACK_HPP
