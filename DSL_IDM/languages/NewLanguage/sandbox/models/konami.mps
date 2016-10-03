<?xml version="1.0" encoding="UTF-8"?>
<model modelUID="r:e65d028e-c17d-44ef-9f6b-3ef16a35ff25(konami)">
  <persistence version="8" />
  <language namespace="e8d00ff4-4c3f-4844-af94-ef2bbda74e49(NewLanguage)" />
  <language namespace="ceab5195-25ea-4f22-9b92-103b95ca8c0c(jetbrains.mps.lang.core)" />
  <language namespace="f3061a53-9226-4cc5-a443-f952ceaf5816(jetbrains.mps.baseLanguage)" />
  <import index="nb7w" modelUID="r:97a90b66-e0bc-4279-9d80-96c3edecfd50(NewLanguage.structure)" version="6" implicit="yes" />
  <root type="nb7w.ArduinoBoard" typeId="nb7w.3007735771312285579" id="6096292100215626894" nodeInfo="ng">
    <property name="frequency" nameId="nb7w.8766321956510187009" value="0" />
    <node role="actuator" roleId="nb7w.3007735771312633009" type="nb7w.Led" typeId="nb7w.8766321956509384918" id="6096292100215626906" nodeInfo="ng">
      <property name="type" nameId="nb7w.3007735771312633033" value="led_rouge" />
      <property name="pinNumber" nameId="nb7w.3007735771312633028" value="10" />
    </node>
    <node role="actuator" roleId="nb7w.3007735771312633009" type="nb7w.Led" typeId="nb7w.8766321956509384918" id="6096292100215626907" nodeInfo="ng">
      <property name="type" nameId="nb7w.3007735771312633033" value="led_verte" />
      <property name="pinNumber" nameId="nb7w.3007735771312633028" value="11" />
    </node>
    <node role="actuator" roleId="nb7w.3007735771312633009" type="nb7w.Buzzer" typeId="nb7w.8766321956509384993" id="6096292100215626908" nodeInfo="ng">
      <property name="type" nameId="nb7w.3007735771312633033" value="buzzer" />
      <property name="pinNumber" nameId="nb7w.3007735771312633028" value="12" />
    </node>
    <node role="actuator" roleId="nb7w.3007735771312633009" type="nb7w.Joystick" typeId="nb7w.8766321956509414161" id="6096292100215626909" nodeInfo="ng">
      <property name="pinNumber" nameId="nb7w.3007735771312633028" value="10" />
      <property name="xAxisPin" nameId="nb7w.8766321956514334882" value="2" />
      <property name="yAxisPin" nameId="nb7w.8766321956514369649" value="1" />
      <property name="type" nameId="nb7w.3007735771312633033" value="joystick" />
    </node>
    <node role="konami" roleId="nb7w.8766321956509414773" type="nb7w.konami" typeId="nb7w.8766321956509384798" id="6096292100215626910" nodeInfo="ng">
      <property name="command" nameId="nb7w.8766321956509552292" value="UP DOWN RIGHT LEFT" />
      <link role="joystick" roleId="nb7w.8766321956509414581" targetNodeId="6096292100215626909" />
      <link role="ledA" roleId="nb7w.8766321956509414398" targetNodeId="6096292100215626906" />
      <link role="ledB" roleId="nb7w.8766321956509414457" targetNodeId="6096292100215626907" />
      <link role="buzzer" roleId="nb7w.8766321956509414518" targetNodeId="6096292100215626908" />
    </node>
  </root>
</model>

