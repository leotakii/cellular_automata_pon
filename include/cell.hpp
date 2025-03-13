#pragma once
#include "global_includes.hpp"
struct Cell : NOP::FBE
{
  NOP::SharedAttribute<int>  atID{NOP::BuildAttribute(0)};

  NOP::SharedAttribute<bool> atState{NOP::BuildAttribute(false)}; //default as false
  
  NOP::SharedAttribute<bool> atStateLeft{NOP::BuildAttribute(false)}; //neighboorhood
  NOP::SharedAttribute<bool> atStateRight{NOP::BuildAttribute(false)};

  NOP::SharedAttribute<bool> atTransitionState{NOP::BuildAttribute(false)}; //next state
  
  NOP::SharedAttribute<bool> atAllReady{NOP::BuildAttribute(false)}; //flag for synchronicity purposes

  NOP::SharedAttribute<int> atElemAutomataRuleID{NOP::BuildAttribute(0)}; //TODO To be implemented: dynamic rule changes

  NOP::SharedAttribute<int> atChanges{NOP::BuildAttribute(0)}; //remembers how many times the state was changed. TODO check *overflow*
  NOP::SharedAttribute<int> atRuleExecuted{NOP::BuildAttribute(0)}; //it is used to count how many times the cells' states change in a given loop 

  //2^3 rules for Elementar Cellular Automata 
  NOP::SharedRule rl000;
  NOP::SharedRule rl001;
  NOP::SharedRule rl010;
  NOP::SharedRule rl011;
  NOP::SharedRule rl100;
  NOP::SharedRule rl101;
  NOP::SharedRule rl110;
  NOP::SharedRule rl111;
  //NOP::SharedRule rlMaster;

  void setID(int id) const {
    atID->SetValue(id);
  }

   void activate() const
  {
    //std::cout << atID->GetValue() <<"A"<< std::endl;
    atRuleExecuted->SetValue(1);
    atTransitionState->SetValue(true);
    atChanges->SetValue(atChanges->GetValue()+1);

  }

  void deactivate() const {
    //std::cout << atID->GetValue() <<"D"<< std::endl;
    atRuleExecuted->SetValue(1);
    atTransitionState->SetValue(false);
    atChanges->SetValue(atChanges->GetValue()+1);

  }

  void ready() const{
    atAllReady->SetValue(true);
  }
  void unready() const{
    atAllReady->SetValue(false);
    atState->SetValue(atTransitionState->GetValue());
    //atTransitionState->SetValue(atState->GetValue());
  }

  void setNeighbors_1D(bool left, bool right) const {
    atStateLeft->SetValue(left);
    atStateRight->SetValue(right);
    atRuleExecuted->SetValue(0);
  }

   void setElemAutomataRuleID(int elemAutomataID) const{
    atElemAutomataRuleID->SetValue(elemAutomataID);
  }
  /*
  void transition() const{ //transition for master rule (not implemented)
    switch (atElemAutomataRuleID->GetValue()) {
    case 30: //executes rule 30 
      atState->SetValue(atStateLeft->GetValue() ^ (atState->GetValue() || atStateRight->GetValue()));
      break;
    case 90: //executes rule 90
      atState->SetValue(atStateLeft->GetValue() ^ atStateRight->GetValue());
    case 110: //executes rule 110
      atState->SetValue(!atStateLeft->GetValue() && atStateRight->GetValue() || (atState->GetValue() ^ atStateRight->GetValue()));
      break;
    case 250: //executes rule 250
      atState->SetValue(atStateLeft->GetValue() || atStateRight->GetValue());
    case 254: //executes rule 254
      atState->SetValue(atStateLeft->GetValue() || atStateRight->GetValue() || atState->GetValue());
    default:
      break;

    }
  }
  */

  Cell(int ElemAutomataRuleID)
  {
  atElemAutomataRuleID->SetValue(ElemAutomataRuleID);
  //commented rules imply in no state changes:             true -> true or false -> false 
  //https://en.wikipedia.org/wiki/Rule_30
  //it can be defined as the boolean expression left_cell XOR (center_cell OR right_cell )

  switch(atElemAutomataRuleID->GetValue()){
    case 30:
      RULE(&rl001);
        LCONDITION();
          CEXP(atStateLeft == false) AND CEXP(atState == false) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl100);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == false) AND CEXP(atStateRight == false)  AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0) ;
        END_CONDITION;
        ACTION();
        INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl110);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == true) AND CEXP(atStateRight == false)  AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0) ;
        END_CONDITION;
        ACTION();
        INSTIGATE(METHOD(this->deactivate();));
        END_ACTION;
      END_RULE;   

      RULE(&rl111);
      LCONDITION();
        CEXP(atStateLeft == true) AND CEXP(atState == true) AND CEXP(atStateRight == true)  AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0) ;
      END_CONDITION;
      ACTION();
        INSTIGATE(METHOD(this->deactivate();));
      END_ACTION;
      END_RULE;
      break;

    case 110:
      RULE(&rl001);
        LCONDITION();
          CEXP(atStateLeft == false) AND CEXP(atState == false) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl101);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == false) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0) ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl111);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == true) AND CEXP(atStateRight == true)  AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0) ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->deactivate();));
        END_ACTION;
      END_RULE;
      break;

    case 90:
      RULE(&rl001);
        LCONDITION();
          CEXP(atStateLeft == false) AND CEXP(atState == false) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl010);
        LCONDITION();
          CEXP(atStateLeft == false) AND CEXP(atState == true) AND CEXP(atStateRight == false) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->deactivate();));
        END_ACTION;
      END_RULE;

      RULE(&rl100);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == false) AND CEXP(atStateRight == false) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl111);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == true) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->deactivate();));
        END_ACTION;
      END_RULE;
      break;
      
      case 184:
      RULE(&rl010);
        LCONDITION();
          CEXP(atStateLeft == false) AND CEXP(atState == true) AND CEXP(atStateRight == false) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->deactivate();));
        END_ACTION;
      END_RULE;

      RULE(&rl100);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == false) AND CEXP(atStateRight == false) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl101);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == false) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl110);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == true) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->deactivate();));
        END_ACTION;
      END_RULE;
      break;
      case 250: //executes rule 250
      RULE(&rl001);
        LCONDITION();
          CEXP(atStateLeft == false) AND CEXP(atState == false) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl010);
        LCONDITION();
          CEXP(atStateLeft == false) AND CEXP(atState == true) AND CEXP(atStateRight == false) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->deactivate();));
        END_ACTION;
      END_RULE;

      RULE(&rl100);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == false) AND CEXP(atStateRight == false) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl101);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == false) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;
        
      break;
      case 254: //executes rule 254. Makes a triangle
      RULE(&rl001);
        LCONDITION();
          CEXP(atStateLeft == false) AND CEXP(atState == false) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl100);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == false) AND CEXP(atStateRight == false) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;

      RULE(&rl101);
        LCONDITION();
          CEXP(atStateLeft == true) AND CEXP(atState == false) AND CEXP(atStateRight == true) AND CEXP(atAllReady == true) AND CEXP(atRuleExecuted == 0)  ;
        END_CONDITION;
        ACTION();
          INSTIGATE(METHOD(this->activate();));
        END_ACTION;
      END_RULE;
      break;
  }
  /*
  
   RULE(&rlMaster);
      LCONDITION();
        CEXP(atAllReady == true);
      END_CONDITION;
      ACTION();
        INSTIGATE(METHOD(this->transition();));
      END_ACTION;
    END_RULE;
  */
  }
};
