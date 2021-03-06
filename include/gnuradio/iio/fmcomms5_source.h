/* -*- c++ -*- */
/* 
 * Copyright 2014 Analog Devices Inc.
 * Author: Paul Cercueil <paul.cercueil@analog.com>
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_IIO_FMCOMMS5_SOURCE_H
#define INCLUDED_IIO_FMCOMMS5_SOURCE_H

#include <gnuradio/iio/api.h>
#include <gnuradio/sync_block.h>

#include "device_source.h"

namespace gr {
  namespace iio {

    /*!
     * \brief <+description of block+>
     * \ingroup iio
     *
     */
    class IIO_API fmcomms5_source : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<fmcomms5_source> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of iio::device.
       *
       * To avoid accidental use of raw pointers, iio::device's
       * constructor is in a private implementation
       * class. iio::device::make is the public interface for
       * creating new instances.
       */
      static sptr make(const std::string &uri, unsigned long long frequency1,
		    unsigned long long frequency2,
		    unsigned long samplerate, unsigned long decimation,
		    unsigned long bandwidth,
		    bool ch1_en, bool ch2_en, bool ch3_en, bool ch4_en,
		    bool ch5_en, bool ch6_en, bool ch7_en, bool ch8_en,
		    unsigned long buffer_size, bool quadrature, bool rfdc,
		    bool bbdc, const char *gain1, double gain1_value,
		    const char *gain2, double gain2_value,
		    const char *gain3, double gain3_value,
		    const char *gain4, double gain4_value,
		    const char *rf_port_select, const char *filter = "");

      static sptr make_from(struct iio_context *ctx,
		    unsigned long long frequency1,
		    unsigned long long frequency2, unsigned long samplerate,
		    unsigned long decimation, unsigned long bandwidth,
		    bool ch1_en, bool ch2_en, bool ch3_en, bool ch4_en,
		    bool ch5_en, bool ch6_en, bool ch7_en, bool ch8_en,
		    unsigned long buffer_size, bool quadrature, bool rfdc,
		    bool bbdc, const char *gain1, double gain1_value,
		    const char *gain2, double gain2_value,
		    const char *gain3, double gain3_value,
		    const char *gain4, double gain4_value,
		    const char *rf_port_select, const char *filter = "");

      virtual void set_params(unsigned long long frequency1,
		      unsigned long long frequency2,
		      unsigned long samplerate, unsigned long bandwidth,
		      bool quadrature, bool rfdc, bool bbdc,
		      const char *gain1, double gain1_value,
		      const char *gain2, double gain2_value,
		      const char *gain3, double gain3_value,
		      const char *gain4, double gain4_value,
		      const char *rf_port_select) = 0;
    };

  } // namespace iio
} // namespace gr

#endif /* INCLUDED_IIO_FMCOMMS2_SOURCE_H */

