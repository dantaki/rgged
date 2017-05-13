# rgged
Alter or Add Read Group Tags to BAM Files with C++

## Install

#### Clone from GitHub

```
git clone --recursive https://github.com/dantaki/rgged.git
```

#### Compile with [CMake](https://cmake.org/)

```
cd rgged/
mkdir build
cd build/

cmake .. 

make 
```

##### Binary executable found under `rgged/build/src/rgged`

## Usage 

`rgged --help`

```
rgged        Alter or Add Read Group (RG) Information

---------------------------------------------------
 WARNING!     Existing Read Groups will be erased!
---------------------------------------------------

Version: 1.0	Author: Danny Antaki <dantaki@ucsd.edu>

Usage: rgged -i <in.bam> -id <ID> -lb <LIBRARY> -pl <PLATFORM> -sm <SAMPLE> >output.bam

Options:
    -i        Input: BAM filename
    -id       ID
    -lb       Library
    -pl       Platform
    -sm       Sample
```

## Acknowledgements

rgged uses [BamTools](https://github.com/pezmaster31/bamtools) and [zlib](http://zlib.net/)

> *BamTools*
> Copyright (c) 2009-2010 Derek Barnett, Erik Garrison, Gabor Marth, Michael Stromberg

> *zlib*
> Copyright (C) 1995-2012 Jean-loup Gailly and Mark Adler

## License

MIT License

Copyright (c) 2017 Danny Antaki

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Contact

dantaki@ucsd.edu
