#ifndef IGLOO_ROOTNODE_H
#define IGLOO_ROOTNODE_H

#include "syntaxtree/iexpressionowner.h"
#include "syntaxtree/binarynode.h"
#include "syntaxtree/unarynode.h"
#include "syntaxtree/constraintnode.h"

namespace igloo {

/*   template <typename ConstraintOperationsType> */
/*     class NodeOwner : public INodeOwner<ConstraintOperationsType> */
/*   { */
/*   public: */
/*     explicit NodeOwner(Expression& expression) : m_expression(expression) {} */

/*     UnaryNode<ConstraintOperationsType>& GetUnaryNode() */
/*     { */
/*       if(m_unaryNode.get() == NULL) */
/*       { */
/*         m_unaryNode = std::auto_ptr<UnaryNode<ConstraintOperationsType> >(new UnaryNode<ConstraintOperationsType>(m_expression, *this)); */
/*       } */

/*       return *(m_unaryNode.get()); */
/*     } */

/*     BinaryNode<ConstraintOperationsType>& GetBinaryNode() */
/*     { */
/*       if(m_binaryNode.get() == NULL) */
/*       { */
/*         m_binaryNode = std::auto_ptr<BinaryNode<ConstraintOperationsType> >(new BinaryNode<ConstraintOperationsType>(m_expression, *this)); */
/*       } */

/*       return *(m_binaryNode.get()); */
/*     } */

/*     ConstraintNode<ConstraintOperationsType>& GetConstraintNode() */
/*     { */
/*       if(m_constraintNode.get() == NULL) */
/*       { */
/*         m_constraintNode = std::auto_ptr<ConstraintNode<ConstraintOperationsType> >(new ConstraintNode<ConstraintOperationsType>(m_expression, *this)); */
/*       } */

/*       return *(m_constraintNode.get()); */
/*     } */

/*   private: */
/*     Expression& m_expression; */
/*     std::auto_ptr<UnaryNode<ConstraintOperationsType> > m_unaryNode; */
/*     std::auto_ptr<BinaryNode<ConstraintOperationsType> > m_binaryNode; */
/*     std::auto_ptr<ConstraintNode<ConstraintOperationsType> > m_constraintNode; */
/*   }; */

  template <typename OperationsType>
    class RootNode : public BinaryNode<OperationsType, RootExpressionItem>
  {
  public:
    explicit RootNode() : BinaryNode<OperationsType, RootExpressionItem>(std::auto_ptr<RootExpressionItem>(new RootExpressionItem())) 
    { 
    }

    RootNode<StringConstraintOperations<RootExpressionItem> >& String()
    {
      m_stringRoot = std::auto_ptr<RootNode<StringConstraintOperations<RootExpressionItem> > >(new RootNode<StringConstraintOperations<RootExpressionItem> >());
      return *(m_stringRoot.get());
    }

  private:
    std::auto_ptr<RootNode<StringConstraintOperations<RootExpressionItem> > > m_stringRoot;
  };

}

#endif
