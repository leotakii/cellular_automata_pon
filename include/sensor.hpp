#pragma once
#include "global_includes.hpp"

struct Sensor : NOP::FBE
{
  NOP::SharedAttribute<bool> atIsRead{NOP::BuildAttribute(false)};
  NOP::SharedAttribute<bool> atIsActivated{NOP::BuildAttribute(false)};

  NOP::SharedRule rlSensor;

  void activate() const
  {
    atIsActivated->SetValue(true);
    atIsRead->SetValue(false);
  }
  
  void read() const { 
    atIsRead->SetValue(true); 
  }
  
  void deactivate() const {
    atIsActivated->SetValue(false);
  }

  Sensor()
  {
    RULE(&rlSensor);
      LCONDITION();
        CEXP(atIsActivated == true) AND CEXP(atIsRead == false);
      END_CONDITION;
      ACTION();
        INSTIGATE(METHOD(this->read(); this->deactivate();));
      END_ACTION;
    END_RULE;
  }
};
