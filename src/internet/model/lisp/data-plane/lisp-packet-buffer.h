/*
 * lisp-packet-buffer.h
 *
 *  Created on: May 2, 2017
 *      Author: qsong
 */

#ifndef SRC_INTERNET_MODEL_LISP_DATA_PLANE_LISP_PACKET_BUFFER_H_
#define SRC_INTERNET_MODEL_LISP_DATA_PLANE_LISP_PACKET_BUFFER_H_

#include "ns3/packet.h"
#include "ns3/ptr.h"
#include "ns3/simple-ref-count.h"

namespace ns3
{

  class LispPacketBuffer
  {
  public:
    LispPacketBuffer ();
    virtual
    ~LispPacketBuffer ();
  };

} /* namespace ns3 */

#endif /* SRC_INTERNET_MODEL_LISP_DATA_PLANE_LISP_PACKET_BUFFER_H_ */
