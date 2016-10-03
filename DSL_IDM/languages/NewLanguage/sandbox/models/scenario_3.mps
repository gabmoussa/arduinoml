<?xml version="1.0" encoding="UTF-8"?>
<model modelUID="r:0252b294-64cb-4364-a53c-567385c4f726(scenario_3)">
  <persistence version="8" />
  <language namespace="e8d00ff4-4c3f-4844-af94-ef2bbda74e49(NewLanguage)" />
  <language namespace="ceab5195-25ea-4f22-9b92-103b95ca8c0c(jetbrains.mps.lang.core)" />
  <language namespace="f3061a53-9226-4cc5-a443-f952ceaf5816(jetbrains.mps.baseLanguage)" />
  <import index="tpee" modelUID="r:00000000-0000-4000-0000-011c895902ca(jetbrains.mps.baseLanguage.structure)" version="5" implicit="yes" />
  <import index="nb7w" modelUID="r:97a90b66-e0bc-4279-9d80-96c3edecfd50(NewLanguage.structure)" version="6" implicit="yes" />
  <root type="nb7w.ArduinoBoard" typeId="nb7w.3007735771312285579" id="6096292100217134272" nodeInfo="ng">
    <property name="frequency" nameId="nb7w.8766321956510187009" value="0" />
    <node role="state" roleId="nb7w.3007735771312633011" type="nb7w.State" typeId="nb7w.3007735771312306397" id="6096292100217134273" nodeInfo="ng">
      <property name="name" nameId="nb7w.3334193164823071057" value="init_sce3" />
      <node role="loop" roleId="nb7w.3679996761108425513" type="tpee.BooleanConstant" typeId="tpee.1068580123137" id="6096292100217134274" nodeInfo="nn">
        <property name="value" nameId="tpee.1068580123138" value="false" />
      </node>
      <node role="action" roleId="nb7w.8136607136727170650" type="nb7w.Action" typeId="nb7w.3007735771312306407" id="6096292100217134275" nodeInfo="ng">
        <link role="actuator" roleId="nb7w.3007735771312633063" targetNodeId="6096292100217134291" />
      </node>
      <node role="transitions" roleId="nb7w.3007735771312633090" type="nb7w.Transition" typeId="nb7w.3007735771312306398" id="6096292100217134276" nodeInfo="ng">
        <link role="nextStateRef" roleId="nb7w.8766321956514820299" targetNodeId="6096292100217134278" resolveInfo="press_off_sce3" />
        <node role="conditions" roleId="nb7w.3007735771312633113" type="nb7w.Condition" typeId="nb7w.3007735771312339831" id="6096292100217134277" nodeInfo="ng">
          <property name="actuatorState" nameId="nb7w.3007735771312633139" value="1" />
          <link role="actuatorRef" roleId="nb7w.480550422802581299" targetNodeId="6096292100217134292" />
        </node>
      </node>
    </node>
    <node role="state" roleId="nb7w.3007735771312633011" type="nb7w.State" typeId="nb7w.3007735771312306397" id="6096292100217134278" nodeInfo="ng">
      <property name="name" nameId="nb7w.3334193164823071057" value="press_off_sce3" />
      <node role="loop" roleId="nb7w.3679996761108425513" type="tpee.BooleanConstant" typeId="tpee.1068580123137" id="6096292100217134279" nodeInfo="nn">
        <property name="value" nameId="tpee.1068580123138" value="false" />
      </node>
      <node role="transitions" roleId="nb7w.3007735771312633090" type="nb7w.Transition" typeId="nb7w.3007735771312306398" id="6096292100217134280" nodeInfo="ng">
        <link role="nextStateRef" roleId="nb7w.8766321956514820299" targetNodeId="6096292100217134282" resolveInfo="released_on_sce3" />
        <node role="conditions" roleId="nb7w.3007735771312633113" type="nb7w.Condition" typeId="nb7w.3007735771312339831" id="6096292100217134281" nodeInfo="ng">
          <link role="actuatorRef" roleId="nb7w.480550422802581299" targetNodeId="6096292100217134292" />
        </node>
      </node>
    </node>
    <node role="state" roleId="nb7w.3007735771312633011" type="nb7w.State" typeId="nb7w.3007735771312306397" id="6096292100217134282" nodeInfo="ng">
      <property name="name" nameId="nb7w.3334193164823071057" value="released_on_sce3" />
      <node role="loop" roleId="nb7w.3679996761108425513" type="tpee.BooleanConstant" typeId="tpee.1068580123137" id="6096292100217134283" nodeInfo="nn">
        <property name="value" nameId="tpee.1068580123138" value="false" />
      </node>
      <node role="action" roleId="nb7w.8136607136727170650" type="nb7w.Action" typeId="nb7w.3007735771312306407" id="6096292100217134284" nodeInfo="ng">
        <property name="nextActuatorState" nameId="nb7w.2275373783512032379" value="1" />
        <link role="actuator" roleId="nb7w.3007735771312633063" targetNodeId="6096292100217134291" />
      </node>
      <node role="transitions" roleId="nb7w.3007735771312633090" type="nb7w.Transition" typeId="nb7w.3007735771312306398" id="6096292100217134285" nodeInfo="ng">
        <link role="nextStateRef" roleId="nb7w.8766321956514820299" targetNodeId="6096292100217134287" resolveInfo="pressed_on_sce3" />
        <node role="conditions" roleId="nb7w.3007735771312633113" type="nb7w.Condition" typeId="nb7w.3007735771312339831" id="6096292100217134286" nodeInfo="ng">
          <property name="actuatorState" nameId="nb7w.3007735771312633139" value="1" />
          <link role="actuatorRef" roleId="nb7w.480550422802581299" targetNodeId="6096292100217134292" />
        </node>
      </node>
    </node>
    <node role="state" roleId="nb7w.3007735771312633011" type="nb7w.State" typeId="nb7w.3007735771312306397" id="6096292100217134287" nodeInfo="ng">
      <property name="name" nameId="nb7w.3334193164823071057" value="pressed_on_sce3" />
      <node role="loop" roleId="nb7w.3679996761108425513" type="tpee.BooleanConstant" typeId="tpee.1068580123137" id="6096292100217134288" nodeInfo="nn">
        <property name="value" nameId="tpee.1068580123138" value="false" />
      </node>
      <node role="transitions" roleId="nb7w.3007735771312633090" type="nb7w.Transition" typeId="nb7w.3007735771312306398" id="6096292100217134289" nodeInfo="ng">
        <link role="nextStateRef" roleId="nb7w.8766321956514820299" targetNodeId="6096292100217134273" resolveInfo="init_sce3" />
        <node role="conditions" roleId="nb7w.3007735771312633113" type="nb7w.Condition" typeId="nb7w.3007735771312339831" id="6096292100217134290" nodeInfo="ng">
          <link role="actuatorRef" roleId="nb7w.480550422802581299" targetNodeId="6096292100217134292" />
        </node>
      </node>
    </node>
    <node role="actuator" roleId="nb7w.3007735771312633009" type="nb7w.Led" typeId="nb7w.8766321956509384918" id="6096292100217134291" nodeInfo="ng">
      <property name="type" nameId="nb7w.3007735771312633033" value="ledScenario3" />
      <property name="pinNumber" nameId="nb7w.3007735771312633028" value="11" />
    </node>
    <node role="actuator" roleId="nb7w.3007735771312633009" type="nb7w.Button" typeId="nb7w.2275373783511842542" id="6096292100217134292" nodeInfo="ng">
      <property name="type" nameId="nb7w.3007735771312633033" value="buttonScenario3" />
      <property name="pinNumber" nameId="nb7w.3007735771312633028" value="12" />
    </node>
  </root>
</model>

