/* 
* File:   operator.h
* Author: joakim
*
* Created on December 13, 2009, 11:05 AM
*/

#ifndef _OPERATOR_H
#define	_OPERATOR_H
namespace igloo {
   class Operator
   {
   public:
      virtual void Evaluate(std::stack<bool>& boolStack) const = 0;
      virtual bool IsLeftAssociative() const = 0;
      virtual void ToString(std::string& str) const = 0;
   };
}
#endif	/* _OPERATOR_H */

