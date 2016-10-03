package NewLanguage.structure;

/*Generated by MPS */

import jetbrains.mps.smodel.PropertySupport;
import java.util.Iterator;
import jetbrains.mps.internal.collections.runtime.ListSequence;

public class Actuator_State_PropertySupport extends PropertySupport {
  public boolean canSetValue(String value) {
    if (value == null) {
      return true;
    }
    Iterator<Actuator_State> constants = ListSequence.fromList(Actuator_State.getConstants()).iterator();
    while (constants.hasNext()) {
      Actuator_State constant = constants.next();
      if (value.equals(constant.getName())) {
        return true;
      }
    }
    return false;
  }

  public String toInternalValue(String value) {
    if (value == null) {
      return null;
    }
    Iterator<Actuator_State> constants = ListSequence.fromList(Actuator_State.getConstants()).iterator();
    while (constants.hasNext()) {
      Actuator_State constant = constants.next();
      if (value.equals(constant.getName())) {
        return constant.getValueAsString();
      }
    }
    return null;
  }

  public String fromInternalValue(String value) {
    Actuator_State constant = Actuator_State.parseValue(value);
    if (constant != null) {
      return constant.getName();
    }
    return "";
  }
}