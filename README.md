# PI_SybilAttackDetecting
A mechanism for detecting a Sybil Attack in a ad-hoc network with IoT applications.
In order to achieve a IoT network we're using arduino and LoRa Heltec. The implementation is performed with c++ classes which represent a node and a sybil node (this one exchange many identities in the network).

## Version 1.0

This version discard Nodes who are not suspected. In order to achieve it, the node receives
a message of type "Hello" and reads its RSSI. When the node has received 10 messages of
"Hello", it compute a compute in order to get an error of distance and take a decision.

### Considerations

1. We assume two nodes in the network (for this first version).
2. This version don't compute distances.
3. This version only use a Serial print (Arduino) to get results.

## Version 1.1

On this version we worked at Documentable function as generator of a
report to sybil nodes detected.

## Notes : 


