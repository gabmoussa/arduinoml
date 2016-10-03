<?xml version="1.0" encoding="UTF-8"?>
<model modelUID="r:5366b660-fd08-41c9-91c3-e044e6da671b(scenario_1)">
  <persistence version="8" />
  <language namespace="e8d00ff4-4c3f-4844-af94-ef2bbda74e49(NewLanguage)" />
  <language namespace="ceab5195-25ea-4f22-9b92-103b95ca8c0c(jetbrains.mps.lang.core)" />
  <language namespace="f3061a53-9226-4cc5-a443-f952ceaf5816(jetbrains.mps.baseLanguage)" />
  <import index="tpee" modelUID="r:00000000-0000-4000-0000-011c895902ca(jetbrains.mps.baseLanguage.structure)" version="5" implicit="yes" />
  <import index="nb7w" modelUID="r:97a90b66-e0bc-4279-9d80-96c3edecfd50(NewLanguage.structure)" version="6" implicit="yes" />
  <root type="nb7w.ArduinoBoard" typeId="nb7w.3007735771312285579" id="6096292100215121892" nodeInfo="ng">
    <property name="frequency" nameId="nb7w.8766321956510187009" value="0.4" />
    <node role="state" roleId="nb7w.3007735771312633011" type="nb7w.State" typeId="nb7w.3007735771312306397" id="6096292100215231676" nodeInfo="ng">
      <property name="name" nameId="nb7w.3334193164823071057" value="initScenario1" />
      <node role="action" roleId="nb7w.8136607136727170650" type="nb7w.Action" typeId="nb7w.3007735771312306407" id="6096292100215231686" nodeInfo="ng">
        <link role="actuator" roleId="nb7w.3007735771312633063" targetNodeId="6096292100215231658" />
      </node>
      <node role="action" roleId="nb7w.8136607136727170650" type="nb7w.Action" typeId="nb7w.3007735771312306407" id="6096292100215288095" nodeInfo="ng">
        <link role="actuator" roleId="nb7w.3007735771312633063" targetNodeId="6096292100215231663" />
      </node>
      <node role="loop" roleId="nb7w.3679996761108425513" type="tpee.BooleanConstant" typeId="tpee.1068580123137" id="6096292100215231678" nodeInfo="nn">
        <property name="value" nameId="tpee.1068580123138" value="false" />
      </node>
      <node role="transitions" roleId="nb7w.3007735771312633090" type="nb7w.Transition" typeId="nb7w.3007735771312306398" id="6096292100215288108" nodeInfo="ng">
        <link role="nextStateRef" roleId="nb7w.8766321956514820299" targetNodeId="6096292100215288110" resolveInfo="pressedScenario1" />
        <node role="conditions" roleId="nb7w.3007735771312633113" type="nb7w.Condition" typeId="nb7w.3007735771312339831" id="6096292100215288156" nodeInfo="ng">
          <property name="actuatorState" nameId="nb7w.3007735771312633139" value="1" />
          <link role="actuatorRef" roleId="nb7w.480550422802581299" targetNodeId="6096292100215231671" />
        </node>
      </node>
    </node>
    <node role="state" roleId="nb7w.3007735771312633011" type="nb7w.State" typeId="nb7w.3007735771312306397" id="6096292100215288110" nodeInfo="ng">
      <property name="name" nameId="nb7w.3334193164823071057" value="pressedScenario1" />
      <node role="action" roleId="nb7w.8136607136727170650" type="nb7w.Action" typeId="nb7w.3007735771312306407" id="6096292100215288125" nodeInfo="ng">
        <property name="nextActuatorState" nameId="nb7w.2275373783512032379" value="1" />
        <link role="actuator" roleId="nb7w.3007735771312633063" targetNodeId="6096292100215231658" />
      </node>
      <node role="action" roleId="nb7w.8136607136727170650" type="nb7w.Action" typeId="nb7w.3007735771312306407" id="6096292100215288158" nodeInfo="ng">
        <property name="nextActuatorState" nameId="nb7w.2275373783512032379" value="1" />
        <link role="actuator" roleId="nb7w.3007735771312633063" targetNodeId="6096292100215231663" />
      </node>
      <node role="loop" roleId="nb7w.3679996761108425513" type="tpee.BooleanConstant" typeId="tpee.1068580123137" id="6096292100215288117" nodeInfo="nn">
        <property name="value" nameId="tpee.1068580123138" value="false" />
      </node>
      <node role="transitions" roleId="nb7w.3007735771312633090" type="nb7w.Transition" typeId="nb7w.3007735771312306398" id="6096292100215288161" nodeInfo="ng">
        <link role="nextStateRef" roleId="nb7w.8766321956514820299" targetNodeId="6096292100215231676" resolveInfo="initScenario1" />
        <node role="conditions" roleId="nb7w.3007735771312633113" type="nb7w.Condition" typeId="nb7w.3007735771312339831" id="6096292100215288163" nodeInfo="ng">
          <link role="actuatorRef" roleId="nb7w.480550422802581299" targetNodeId="6096292100215231671" />
        </node>
      </node>
    </node>
    <node role="actuator" roleId="nb7w.3007735771312633009" type="nb7w.Led" typeId="nb7w.8766321956509384918" id="6096292100215231658" nodeInfo="ng">
      <property name="type" nameId="nb7w.3007735771312633033" value="ledScenario1" />
      <property name="pinNumber" nameId="nb7w.3007735771312633028" value="11" />
    </node>
    <node role="actuator" roleId="nb7w.3007735771312633009" type="nb7w.Buzzer" typeId="nb7w.8766321956509384993" id="6096292100215231663" nodeInfo="ng">
      <property name="type" nameId="nb7w.3007735771312633033" value="buzzerScenario1" />
      <property name="pinNumber" nameId="nb7w.3007735771312633028" value="10" />
    </node>
    <node role="actuator" roleId="nb7w.3007735771312633009" type="nb7w.Button" typeId="nb7w.2275373783511842542" id="6096292100215231671" nodeInfo="ng">
      <property name="pinNumber" nameId="nb7w.3007735771312633028" value="12" />
      <property name="type" nameId="nb7w.3007735771312633033" value="buttonScenario1" />
    </node>
  </root>
</model>

