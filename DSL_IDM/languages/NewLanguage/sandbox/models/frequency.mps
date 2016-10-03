<?xml version="1.0" encoding="UTF-8"?>
<model modelUID="r:eec96698-b12b-491a-a6fe-829ba1c984b8(frequency)">
  <persistence version="8" />
  <language namespace="e8d00ff4-4c3f-4844-af94-ef2bbda74e49(NewLanguage)" />
  <language namespace="ceab5195-25ea-4f22-9b92-103b95ca8c0c(jetbrains.mps.lang.core)" />
  <language namespace="f3061a53-9226-4cc5-a443-f952ceaf5816(jetbrains.mps.baseLanguage)" />
  <import index="nb7w" modelUID="r:97a90b66-e0bc-4279-9d80-96c3edecfd50(NewLanguage.structure)" version="6" implicit="yes" />
  <import index="tpee" modelUID="r:00000000-0000-4000-0000-011c895902ca(jetbrains.mps.baseLanguage.structure)" version="5" implicit="yes" />
  <root type="nb7w.ArduinoBoard" typeId="nb7w.3007735771312285579" id="3791455715934954231" nodeInfo="ng">
    <property name="frequency" nameId="nb7w.8766321956510187009" value="0.5" />
    <node role="state" roleId="nb7w.3007735771312633011" type="nb7w.State" typeId="nb7w.3007735771312306397" id="3791455715934988652" nodeInfo="ng">
      <property name="name" nameId="nb7w.3334193164823071057" value="initialFreq" />
      <node role="loop" roleId="nb7w.3679996761108425513" type="tpee.BooleanConstant" typeId="tpee.1068580123137" id="3791455715934988654" nodeInfo="nn">
        <property name="value" nameId="tpee.1068580123138" value="true" />
      </node>
      <node role="action" roleId="nb7w.8136607136727170650" type="nb7w.Action" typeId="nb7w.3007735771312306407" id="3791455715934988662" nodeInfo="ng">
        <property name="delay" nameId="nb7w.8766321956511887182" value="200" />
        <link role="actuator" roleId="nb7w.3007735771312633063" targetNodeId="3791455715934954238" />
      </node>
      <node role="action" roleId="nb7w.8136607136727170650" type="nb7w.Action" typeId="nb7w.3007735771312306407" id="3791455715934988664" nodeInfo="ng">
        <property name="nextActuatorState" nameId="nb7w.2275373783512032379" value="1" />
        <property name="delay" nameId="nb7w.8766321956511887182" value="200" />
        <link role="actuator" roleId="nb7w.3007735771312633063" targetNodeId="3791455715934954238" />
      </node>
      <node role="action" roleId="nb7w.8136607136727170650" type="nb7w.Action" typeId="nb7w.3007735771312306407" id="3791455715934988667" nodeInfo="ng">
        <property name="delay" nameId="nb7w.8766321956511887182" value="200" />
        <link role="actuator" roleId="nb7w.3007735771312633063" targetNodeId="3791455715934954238" />
      </node>
      <node role="action" roleId="nb7w.8136607136727170650" type="nb7w.Action" typeId="nb7w.3007735771312306407" id="3791455715934988671" nodeInfo="ng">
        <property name="nextActuatorState" nameId="nb7w.2275373783512032379" value="1" />
        <property name="delay" nameId="nb7w.8766321956511887182" value="200" />
        <link role="actuator" roleId="nb7w.3007735771312633063" targetNodeId="3791455715934954238" />
      </node>
    </node>
    <node role="actuator" roleId="nb7w.3007735771312633009" type="nb7w.Led" typeId="nb7w.8766321956509384918" id="3791455715934954238" nodeInfo="ng">
      <property name="type" nameId="nb7w.3007735771312633033" value="led" />
      <property name="pinNumber" nameId="nb7w.3007735771312633028" value="11" />
    </node>
  </root>
</model>

