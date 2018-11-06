#pragma once


#include <memory>
#include <QtCore/QUuid>

namespace std
{
    template<> struct hash<QUuid>{
        inline std::size_t  operator()(QUuid const& uid) const{ return qHash(uid);}
    };
}

#if (!defined(_MSC_VER) && (__cplusplus < 201300)) || \
    ( defined(_MSC_VER) && (_MSC_VER < 1900))

namespace std
{
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args){
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

#endif


