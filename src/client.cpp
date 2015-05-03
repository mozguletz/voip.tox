/*
 *      Copyright (C) 2011 Pulse-Eight
 *      http://www.pulse-eight.com/
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "client.h"
#include "kodi/xbmc_voip_dll.h"
#include "kodi/libKODI_guilib.h"
#include "VOIPToxData.h"
#include <kodi/util/util.h>

using namespace std;
using namespace ADDON;

#ifdef TARGET_WINDOWS
#define snprintf _snprintf
#endif

bool           m_bCreated       = false;
ADDON_STATUS   m_CurStatus      = ADDON_STATUS_UNKNOWN;
VOIPToxData   *m_data           = NULL;
bool           m_bIsPlaying     = false;

/* User adjustable settings are saved here.
 * Default values are defined inside client.h
 * and exported to the other source files.
 */
std::string g_strUserPath             = "";
std::string g_strClientPath           = "";

CHelper_libXBMC_addon *XBMC           = NULL;
CHelper_libXBMC_voip  *VOIP           = NULL;

extern "C" {

void ADDON_ReadSettings(void)
{
  //STUB
}

ADDON_STATUS ADDON_Create(void* hdl, void* props)
{
  if (!hdl || !props)
    return ADDON_STATUS_UNKNOWN;

  VOIP_PROPERTIES* pvrprops = (VOIP_PROPERTIES*)props;


  XBMC = new CHelper_libXBMC_addon;

  if (!XBMC->RegisterMe(hdl))
  {
    SAFE_DELETE(XBMC);
    return ADDON_STATUS_PERMANENT_FAILURE;
  }

  VOIP = new CHelper_libXBMC_voip;
  if (!VOIP->RegisterMe(hdl))
  {
    SAFE_DELETE(VOIP);
    SAFE_DELETE(XBMC);
    return ADDON_STATUS_PERMANENT_FAILURE;
  }

  XBMC->Log(LOG_DEBUG, "%s - Creating the VOIP Tox add-on", __FUNCTION__);

  ADDON_ReadSettings();

  m_data = new VOIPToxData;
  m_CurStatus = ADDON_STATUS_OK;
  m_bCreated = true;
  return m_CurStatus;
}

ADDON_STATUS ADDON_GetStatus()
{
  return m_CurStatus;
}

void ADDON_Destroy()
{
  delete m_data;
  m_bCreated = false;
  m_CurStatus = ADDON_STATUS_UNKNOWN;
}

bool ADDON_HasSettings()
{
  return true;
}

unsigned int ADDON_GetSettings(ADDON_StructSetting ***sSet)
{
  return 0;
}

ADDON_STATUS ADDON_SetSetting(const char *settingName, const void *settingValue)
{
  return ADDON_STATUS_OK;
}

void ADDON_Stop()
{
}

void ADDON_FreeSettings()
{
}

void ADDON_Announce(const char *flag, const char *sender, const char *message, const void *data)
{
}


 const char* GetVOIPAPIVersion(void)
  {
    static const char *strApiVersion = XBMC_VOIP_API_VERSION;
    return strApiVersion;
  }

  const char* GetMininumVOIPAPIVersion(void)
  {
    static const char *strMinApiVersion = XBMC_VOIP_MIN_API_VERSION;
    return strMinApiVersion;
  }

  const char* GetGUIAPIVersion(void)
  {
    static const char *strGuiApiVersion = KODI_GUILIB_API_VERSION;
    return strGuiApiVersion;
  }

  const char* GetMininumGUIAPIVersion(void)
  {
    static const char *strMinGuiApiVersion = KODI_GUILIB_MIN_API_VERSION;
    return strMinGuiApiVersion;
  }


VOIP_ERROR GetAddonCapabilities(VOIP_ADDON_CAPABILITIES *pCapabilities)
{
  return VOIP_ERROR_NO_ERROR;
}

const char* GetBackendName(void)
{
  static const char* backendName="aur/tox-git";
  return backendName;
}

const char* GetBackendVersion(void)
{
  static const char* backendVersion="r3350.6a1efc3-1";
  return backendVersion;

}

VOIP_ERROR CallMenuHook(const VOIP_MENUHOOK& menuhook)
{
  return VOIP_ERROR_NOT_IMPLEMENTED;
}

int GetNumberOfContacts(void)
{
  return 0;
}

VOIP_CONTACT *GetContactById(int)
{
  return NULL;
}

VOIP_ERROR GetContact(VOIP_CONTACT&, int)
{
 return VOIP_ERROR_NOT_IMPLEMENTED; 
}

/***********************************************************
 * PVR Client AddOn specific public library functions
 ***********************************************************/

VOIP_ERROR VOIP_add_menu_hook(void* HANDLE, void* CB, VOIP_MENUHOOK *hook) { return VOIP_ERROR_NOT_IMPLEMENTED; }
/** UNUSED API FUNCTIONS */

    
}
