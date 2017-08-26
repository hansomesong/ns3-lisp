/*
 * MapTables.h
 *
 *  Created on: 28 janv. 2016
 *      Author: lionel
 */

#ifndef MAPTABLES_H_
#define MAPTABLES_H_

#include "ns3/packet.h"
#include "locators.h" //it included lisp-protcol.h
#include "ns3/ptr.h"
#include "ns3/simple-ref-count.h"
//#include "lisp-protocol.h"
#include "lisp-over-ip.h"
#include "map-entry.h"

namespace ns3
{

class MapTables : public Object
{
public:

  static TypeId GetTypeId (void);
  MapTables ();
  virtual ~MapTables ();

  virtual Ptr<MapEntry> DatabaseLookup (const Address &eid) = 0;

  virtual Ptr<MapEntry> CacheLookup (const Address &eid) = 0;

  virtual int GetNMapEntries (void)=0;
  /**
   * \brief Get the number of mapping entries in LISP batabase
   * \return the number of mapping entries in LISP database
   */
  virtual int GetNMapEntriesLispDataBase (void)=0;
  /**
   * \brief Get the number of mapping entries in LISP Cache.
   * \return the number of mapping entries in LISP Cache.
   */
  virtual int GetNMapEntriesLispCache (void)=0;

  /**
   * \brief Print the Map Table content to the given output stream
   * \param The output stream to which this SimpleMapTables is printed
   */
  virtual void Print (std::ostream &os) const=0;


  enum MapEntryLocation {
    IN_DATABASE = 0,
    IN_CACHE = 1
  };

  virtual void SetEntry (const Address &eid, const Ipv4Mask &mask, Ptr<MapEntry> mapEntry, MapEntryLocation location) = 0;
  virtual void SetEntry (const Address &eid, const Ipv6Prefix &prefix, Ptr<MapEntry> mapEntry, MapEntryLocation location) = 0;

  virtual void InsertLocator (const Ipv4Address &eid, const Ipv4Mask &mask, const Ipv4Address &rlocAddress, uint8_t priority, uint8_t weight, MapEntryLocation location, bool reachable) = 0;
  virtual void InsertLocator (const Ipv4Address &eid, const Ipv4Mask &mask, const Ipv6Address &rlocAddress, uint8_t priority, uint8_t weight, MapEntryLocation location, bool reachable) = 0;
  virtual void InsertLocator (const Ipv6Address &eid, const Ipv6Prefix &prefix, const Ipv4Address &rlocAddress, uint8_t priority, uint8_t weight, MapEntryLocation location, bool reachable) = 0;
  virtual void InsertLocator (const Ipv6Address &eid, const Ipv6Prefix &prefix, const Ipv6Address &rlocAddress, uint8_t priority, uint8_t weight, MapEntryLocation location, bool reachable) = 0;

  virtual Ptr<Locator> DestinationRlocSelection (Ptr<const MapEntry> remoteMapEntry) = 0;

  virtual Ptr<Locator> SourceRlocSelection (Address const &srcEid, Ptr<const Locator> destLocator) = 0;

  virtual bool IsMapForReceivedPacket (Ptr <const Packet> p, const LispHeader &header, const Address &srcRloc, const Address &destRloc) = 0;

  virtual void GetMapEntryList (MapEntryLocation location, std::list<Ptr<MapEntry> > &entryList) = 0;

  // TODO Add map_notify, map_check_lsbits ?,

  /**
   * Lisp Protocol associated to this MapTables
   * @return
   */
  Ptr<LispOverIp> GetLispOverIp (void);
  void SetLispOverIp (Ptr<LispOverIp> lispProtocol);

  void DbMiss (void);
  void DbHit (void);
  void CacheHit (void);
  void CacheMiss (void);

private:
  Ptr<LispOverIp> m_lispProtocol;

  uint32_t m_dbMiss;    // # failed lookups in db
  uint32_t m_dbHit;     // # successful lookups in db
  uint32_t m_cacheMiss; // # failed lookups in cache
  uint32_t m_cacheHit;  // # successful lookups in cache
};

std::ostream& operator<< (std::ostream &os, MapTables const &mapTable);

} /* namespace ns3 */

#endif /* MAPTABLES_H_ */
