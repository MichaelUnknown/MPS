/**
 * Copyright (c) 2012 Andrew Prock. All rights reserved.
 * $Id: RazzHandEvaluator.h 2649 2012-06-30 04:53:24Z prock $
 */
#ifndef PEVAL_RAZZHANDEVALUATOR_H_
#define PEVAL_RAZZHANDEVALUATOR_H_

#include <pokerstove/peval/PokerHandEvaluator.h>

namespace pokerstove
{
    /**
     * A specialized hand evaluator for hold'em.  Not as slow.
     */
    class RazzHandEvaluator : public PokerHandEvaluator
    {
       public:
        virtual PokerHandEvaluation evaluateHand(const CardSet& hand, const CardSet&) const
        {
            return PokerHandEvaluation(hand.evaluateLowA5());
        }

        virtual PokerEvaluation evaluateRanks(const CardSet& hand, const CardSet& board = CardSet(0)) const { return hand.evaluateLowA5(); }

        virtual bool usesSuits() const { return false; }

        virtual size_t handSize() const { return 7; }
        virtual size_t boardSize() const { return 0; }
        virtual size_t evaluationSize() const { return 1; }
    };

}    // namespace pokerstove
#endif    // PEVAL_RAZZHANDEVALUATOR_H_
