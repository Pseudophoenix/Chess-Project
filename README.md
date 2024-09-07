# Chess-Project
This repo consists of my semester project of creating a chess tool for beginners learning to use the correct steps of various pieces using LDR sensor and Arduino board.

### Tech Used
[![Tech Used](https://skillicons.dev/icons?i=cpp,arduino)](https://skillicons.dev)

### Strategy or Approach:
Objects are the sensors and we simply detect the change in the sensor depending on the initial state of the sensor and the initial piece on the sensor we then look for the next change of sensor and go with the condition that the later one got the piece that was moved from the first one.
**Note**: The strategy may change in the future considering the pieces as the object and storing their occupied sensor's coordinates as attributes. 

**Challenges:**
1. The pieces are currently not detecting the presence of pieces in the path.
