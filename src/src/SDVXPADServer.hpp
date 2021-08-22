#pragma once

#include <memory>

#include "ControllerState.hpp"

struct SDVXPADServer
{
    struct Impl;
    std::unique_ptr<Impl> m_impl;

    SDVXPADServer(int port);
    ~SDVXPADServer();

    void start_server();
    void stop_server();

    uint64_t get_controller_state();
};
