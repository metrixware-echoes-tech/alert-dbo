/* 
 * Alert Tracking Event Table
 * @author ECHOES Technologies (TSA)
 * @date 30/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "message/MessageTrackingEvent.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string MessageTrackingEvent::TRIGRAM(TRIGRAM_MESSAGE_TRACKING_EVENT);

    MessageTrackingEvent::MessageTrackingEvent()
    {
    }

    MessageTrackingEvent::MessageTrackingEvent(const MessageTrackingEvent& orig)
    {
    }

    MessageTrackingEvent::~MessageTrackingEvent()
    {
    }
  }
}

