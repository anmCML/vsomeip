// Copyright (C) 2014 BMW Group
// Author: Lutz Bichler (lutz.bichler@bmw.de)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef VSOMEIP_ENDPOINT_HPP
#define VSOMEIP_ENDPOINT_HPP

#include <boost/asio/ip/address.hpp>

#include <vsomeip/primitive_types.hpp>

namespace vsomeip {

class endpoint
{
public:
	virtual ~endpoint() {};

	virtual void start() = 0;
	virtual void stop() = 0;

	virtual bool is_connected() const = 0;

	virtual bool send(const byte_t *_data, uint32_t _size, bool _flush = true) = 0;
	virtual bool send_to(const boost::asio::ip::address &_address, uint16_t _port,
	                     const byte_t *_data, uint32_t _size, bool _flush = true) = 0;
	virtual void enable_magic_cookies() = 0;
	virtual void receive() = 0;

	virtual void open_filter(service_t _service_id) = 0;
	virtual void close_filter(service_t _service_id) = 0;

	virtual void join(const std::string &_address) = 0;
	virtual void leave(const std::string &_address) = 0;

	virtual void add_multicast(service_t _service, event_t _event,
			const std::string &_address, uint16_t _port) = 0;
	virtual void remove_multicast(service_t _service, event_t _event) = 0;

	virtual unsigned short get_port() const = 0;
	virtual bool is_reliable() const = 0;
};

} // namespace vsomeip

#endif // VSOMEIP_ENDPOINT_HPP
