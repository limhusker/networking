Event-Based Networking Framework
============================

This file is part of the networking module https://github.com/cgloeckner/networking. The project offers an event-based networking framework for games and other software. It's main purpose is to integrate it into FLARE by Clint Bellanger one day.

The source code is released under CC BY-NC 3.0. Feel free to share and remix this work while using it for non-commercial purpose only. Please mention me as the base of your work. Please read http://creativecommons.org/licenses/by-nc/3.0/ for further information.

Kind regards

Christian Glöckner


Building:
--------

To build the module and demo application using gcc you can use:

	g++ -o demo src/*.cpp example/*.cpp demo.cpp -lSDL

I testet it using GNU/Linux Ubuntu 12.04 32-Bit and gcc 4.6.3.


Scheduled Changes:
----------------

Here are some ideas as my personal to-do-list:

    - write some TCP-/UDP-based demo stuff using sdl_net
    - implement a bidirectional network-based event-pipe class with:
        - incomming, outgoing EventPipes and handling threads
        - mode given in constructor (network::tcp, network::udp)
        - methods to listen/open/close connection

Later usage example:

    BidirectionalNetworkPipe pipe;
    /**
        one internal thread: sending outgoing events to network
        another internal thread: receiving incomming events from network
     */
    pipe.push(myEvent); // push it in outgoing EventPipe
    otherEvent = pipe.pop(); // pop from internal incomming EventPipe
    

