#ifndef MBR_Wave_h
#define MBR_Wave_h

#include <Arduino.h>

// this should be an MBR_Wave
class Wave{
  public: 

    Wave(int size, int scalar){
        this->_size = size;
        this->_scalar = scalar;
    }

    float outputWave(int i, int iMax){
        _radian = i * (2*PI/iMax);  // map radians from index. [0,0] [2Pi,indexMax] // link to drawings somehow...
        float output = _scalar * (_amplitude * sin((2*PI/_period) * (_radian - _x0)) + _y0); 
        return output;
    }

  private:
    float _radian;
    float _amplitude = .5;                 // amplitude is from middle of sine wave to extreme
    float _period = 2*PI;                  // (T) period of sine wave = 1/frequency
    float _x0 = .5*PI;                    // horizontal shift
    float _y0 = .5;                        // vertical shift
    float _size;                            // max wave size
    float _scalar;                          // after normalizing the wave, scale the amplituted       
};

#endif