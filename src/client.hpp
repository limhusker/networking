/*
Copyright © 2013 Christian Glöckner <cgloeckner@freenet.de>

This file is part of the NetworkingQueueing module:
    https://github.com/cgloeckner/NetworkingQueueing

It offers an event-based networking framework for games and other software.

The source code is released under CC BY-NC 3.0
http://creativecommons.org/licenses/by-nc/3.0/
*/

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "connection.hpp"
#include "eventsystem.hpp"

int client_handler(void* param);

class BaseClient {
    friend int client_handler(void* param);
    protected:
        TcpLink link;
        NetworkingQueue* queue;
        SDL_Thread* handle_thread;
        bool running;

        /// Handle given event. The event should be deleted here after handling
        virtual void handle(Event* event) = 0;
        virtual void onConnect() = 0;
        virtual void onDisconnect() = 0;
    public:
        BaseClient(std::string hostname, unsigned short port);
        virtual ~BaseClient();
        
        void run();
        void shutdown();
        template <typename TEvent>
        void push(TEvent* event);
};

template <typename TEvent>
void BaseClient::push(TEvent* event) {
    this->queue->push(event);
}

// @todo: onDisconnect()

#endif
