/* 
* File:   is.h
* Author: joakim
*
* Created on December 9, 2009, 10:28 AM
*/

#ifndef _IS_H
#define	_IS_H

#include "expressionsyntax/syntax.h"

namespace igloo {
   
  Syntax Is()
   {
     Syntax syntax(std::auto_ptr<Expression>(new Expression()));
     return syntax;
   }

}
#endif	/* _IS_H */

