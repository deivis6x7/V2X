//
// Generated file, do not edit! Created by opp_msgtool 6.0 from stack/phy/packet/AirFrame.msg.
//

#ifndef __AIRFRAME_M_H
#define __AIRFRAME_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class AirFrame;
// cplusplus {{
#include "inet/common/INETDefs.h"
#include "inet/common/geometry/common/Coord.h"
#include "stack/phy/packet/ModulationType.h"
// }}

#include "inet/common/geometry/Geometry_m.h" // import inet.common.geometry.Geometry

/**
 * Class generated from <tt>stack/phy/packet/AirFrame.msg:28</tt> by opp_msgtool.
 * <pre>
 * //
 * // Format of the messages that are sent to the channel
 * //
 * // subclass if you want to create your own ~AirFrame message class
 * //
 * packet AirFrame extends cPacket
 * {
 *     double pSend; // Power with which this packet is transmitted
 *     int channelNumber; // Channel on which the packet is sent
 *     simtime_t duration; // Time it takes to transmit the packet, in seconds
 *     double bitrate;
 *     double snr;
 *     double lossRate;
 *     double powRec; // Power in the receiver
 *     inet::Coord senderPos;
 *     double carrierFrequency;
 *     double bandwidth;
 *     ModulationType modulationType;
 * }
 * </pre>
 */
class AirFrame : public ::omnetpp::cPacket
{
  protected:
    double pSend = 0;
    int channelNumber = 0;
    omnetpp::simtime_t duration = SIMTIME_ZERO;
    double bitrate = 0;
    double snr = 0;
    double lossRate = 0;
    double powRec = 0;
    inet::Coord senderPos;
    double carrierFrequency = 0;
    double bandwidth = 0;
    ModulationType modulationType;

  private:
    void copy(const AirFrame& other);

  protected:
    bool operator==(const AirFrame&) = delete;

  public:
    AirFrame(const char *name=nullptr, short kind=0);
    AirFrame(const AirFrame& other);
    virtual ~AirFrame();
    AirFrame& operator=(const AirFrame& other);
    virtual AirFrame *dup() const override {return new AirFrame(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual double getPSend() const;
    virtual void setPSend(double pSend);

    virtual int getChannelNumber() const;
    virtual void setChannelNumber(int channelNumber);

    virtual omnetpp::simtime_t getDuration() const;
    virtual void setDuration(omnetpp::simtime_t duration);

    virtual double getBitrate() const;
    virtual void setBitrate(double bitrate);

    virtual double getSnr() const;
    virtual void setSnr(double snr);

    virtual double getLossRate() const;
    virtual void setLossRate(double lossRate);

    virtual double getPowRec() const;
    virtual void setPowRec(double powRec);

    virtual const inet::Coord& getSenderPos() const;
    virtual inet::Coord& getSenderPosForUpdate() { return const_cast<inet::Coord&>(const_cast<AirFrame*>(this)->getSenderPos());}
    virtual void setSenderPos(const inet::Coord& senderPos);

    virtual double getCarrierFrequency() const;
    virtual void setCarrierFrequency(double carrierFrequency);

    virtual double getBandwidth() const;
    virtual void setBandwidth(double bandwidth);

    virtual const ModulationType& getModulationType() const;
    virtual ModulationType& getModulationTypeForUpdate() { return const_cast<ModulationType&>(const_cast<AirFrame*>(this)->getModulationType());}
    virtual void setModulationType(const ModulationType& modulationType);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const AirFrame& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, AirFrame& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

inline any_ptr toAnyPtr(const ModulationType *p) {if (auto obj = as_cObject(p)) return any_ptr(obj); else return any_ptr(p);}
template<> inline ModulationType *fromAnyPtr(any_ptr ptr) { return ptr.get<ModulationType>(); }
template<> inline AirFrame *fromAnyPtr(any_ptr ptr) { return check_and_cast<AirFrame*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __AIRFRAME_M_H

