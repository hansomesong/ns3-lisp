/*
 * lisp-packet-buffer-impl.h
 *
 *  Created on: May 2, 2017
 *      Author: qsong
 */

#ifndef SRC_INTERNET_MODEL_LISP_DATA_PLANE_LISP_PACKET_BUFFER_IMPL_H_
#define SRC_INTERNET_MODEL_LISP_DATA_PLANE_LISP_PACKET_BUFFER_IMPL_H_

#include "lisp-packet-buffer.h"

namespace ns3
{

  class LispPacketBufferImpl : public LispPacketBuffer
  {
  public:
    LispPacketBufferImpl ();
    virtual
    ~LispPacketBufferImpl ();
  };

} /* namespace ns3 */

#endif /* SRC_INTERNET_MODEL_LISP_DATA_PLANE_LISP_PACKET_BUFFER_IMPL_H_ */
