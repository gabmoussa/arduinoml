package NewLanguage.structure;

/*Generated by MPS */

import java.util.List;
import jetbrains.mps.internal.collections.runtime.ListSequence;
import jetbrains.mps.internal.collections.runtime.backports.LinkedList;

public enum Actuator_State {
  LOW("LOW", 0),
  HIGH("HIGH", 1);

  private String myName;

  public String getName() {
    return this.myName;
  }

  public String getValueAsString() {
    return "" + this.myValue;
  }

  public static List<Actuator_State> getConstants() {
    List<Actuator_State> list = ListSequence.fromList(new LinkedList<Actuator_State>());
    ListSequence.fromList(list).addElement(Actuator_State.LOW);
    ListSequence.fromList(list).addElement(Actuator_State.HIGH);
    return list;
  }

  public static Actuator_State getDefault() {
    return Actuator_State.LOW;
  }

  public static Actuator_State parseValue(String value) {
    if (value == null) {
      return Actuator_State.getDefault();
    }
    if (value.equals(Actuator_State.LOW.getValueAsString())) {
      return Actuator_State.LOW;
    }
    if (value.equals(Actuator_State.HIGH.getValueAsString())) {
      return Actuator_State.HIGH;
    }
    return Actuator_State.getDefault();
  }

  private int myValue;

  Actuator_State(String name, int value) {
    this.myName = name;
    this.myValue = value;
  }

  public int getValue() {
    return this.myValue;
  }
}
