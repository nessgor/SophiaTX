
#pragma once

#include <steem/protocol/authority.hpp>

#include <fc/variant.hpp>

#include <boost/container/flat_set.hpp>

#include <string>
#include <vector>

namespace steem { namespace protocol {

struct get_required_auth_visitor
{
   typedef void result_type;

   flat_set< account_name_type >&        active;
   flat_set< account_name_type >&        owner;
   std::vector< authority >&  other;

   get_required_auth_visitor(
         flat_set< account_name_type >& a,
         flat_set< account_name_type >& own,
         std::vector< authority >& oth )
      : active( a ), owner( own ), other( oth ) {}

   template< typename ...Ts >
   void operator()( const fc::static_variant< Ts... >& v )
   {
      v.visit( *this );
   }

   template< typename T >
   void operator()( const T& v )const
   {
      v.get_required_active_authorities( active );
      v.get_required_owner_authorities( owner );
      v.get_required_authorities( other );
   }
};

} } // steem::protocol

//
// Place STEEM_DECLARE_OPERATION_TYPE in a .hpp file to declare
// functions related to your operation type
//
#define STEEM_DECLARE_OPERATION_TYPE( OperationType )                            \
namespace fc {                                                                   \
                                                                                 \
void to_variant( const OperationType&, fc::variant& );                           \
void from_variant( const fc::variant&, OperationType& );                         \
                                                                                 \
} /* fc */                                                                       \
                                                                                 \
namespace steem { namespace protocol {                                         \
                                                                                 \
void operation_validate( const OperationType& o );                               \
void operation_get_required_authorities( const OperationType& op,                \
                                         flat_set< account_name_type >& active,  \
                                         flat_set< account_name_type >& owner,   \
                                         vector< authority >& other );           \
                                                                                 \
} } /* steem::protocol */