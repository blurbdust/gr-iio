# gr-iio
IIO blocks for GNU Radio
First and foremost, let's list dependencies because someone thought listing dependencies was too hard.

```
git clone https://github.com/analogdevicesinc/libiio.git
cd libiio
mkdir build
cd build
cmake ..
make
sudo make install

git clone https://github.com/analogdevicesinc/libad9361-iio.git
cd libad9361-iio
mkdir build
cd build
cmake ..
make
sudo make install
```

Secondly, I had a ton of trouble getting this to compile and then eventually actually running in the latest GNURadio.
The way it is laid out made sense however eventually failed. When installed I could not run the block. 

The error was "ImportError: cannot import name iio".

/usr/local/lib/python2.7/dist-packages/gnuradio/iio did exist and as far as I am aware that is how one would import something from inside a folder. Maybe gnuradio.iio would have worked? ~~I'll test in a bit.~~ Tested, no go.

```
cd /usr/local/lib/python2.7/dist-packages/
sudo cp -r gnuradio/iio/* .
```
But still no luck. Different error libgnuradio-iio.so not being found. Instead of trying to symlink that everywhere I ran in to errors, I instead decided to change the install path from "/usr/local/lib/python2.7/dist-packages/gnuradio/iio" to "/usr/local/lib/python2.7/dist-packages/iio".

```
git clone https://github.com/analogdevicesinc/gr-iio.git
cd gr-iio
mkdir build
cd build
cmake ..
make
sudo make install
cd ..
rm -r build
mv include/gnuradio/iio include/iio
rm -r include/gnuradio
sed -i 's/gnuradio\/iio/iio/g' CMakeLists.txt
sed -i 's/gnuradio\/iio/iio/g' swig/*
sed -i 's/gnuradio\/iio/iio/g' include/iio/*
sed -i 's/gnuradio\/iio/iio/g' lib/*
sed -i 's/gnuradio\/iio/iio/g' python/iio/*
sed -i 's/from\ gnuradio\ import\ iio/import\ iio/g' grc/iio_pluto_sink.xml
sed -i 's/from\ gnuradio\ import\ iio/import\ iio/g' grc/iio_pluto_source.xml
mkdir build
cd build
cmake ..
make
sudo make install
````

Then I was able to get my PlutoSDR working in GNURadio. This is a terrible way of doing it. And I will look into an actual fix instead of a bandaid. One benefit to doing it this is the ability to install only this block from source and not GNURadio itself as with pyBOMBS so it'd be possible to use a prebuilt GNURadio like on a RPi. Or if you are like me and have a lot of issues with pyBOMBS.

![](http://i.imgur.com/njOslE3.png)
