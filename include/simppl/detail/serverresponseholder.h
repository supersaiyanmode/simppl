#ifndef SIMPPL_DETAIL_SERVERRESPONSEHOLDER_H
#define SIMPPL_DETAIL_SERVERRESPONSEHOLDER_H


#include <cstdint>
#include <sys/types.h>


// forward decls
struct ServerResponseBase;


namespace detail
{

struct Serializer;


struct ServerResponseHolder 
{
   ServerResponseHolder(Serializer& s, ServerResponseBase& responder);
   
   ~ServerResponseHolder();
   
   ServerResponseHolder(ServerResponseHolder&& rhs);
   ServerResponseHolder& operator=(ServerResponseHolder&& rhs);
   
   ServerResponseHolder(const ServerResponseHolder& rhs) = delete;
   ServerResponseHolder& operator=(const ServerResponseHolder& rhs) = delete;
   
   /*mutable*/ size_t size_;
   /*mutable*/ void* payload_;
   /*mutable*/ ServerResponseBase* responder_;
};

}   // namespace detail


#endif   // SIMPPL_DETAIL_SERVERRESPONSEHOLDER_H