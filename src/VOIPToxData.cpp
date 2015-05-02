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

#include "kodi/util/XMLUtils.h"
#include "VOIPToxData.h"

using namespace std;
using namespace ADDON;

VOIPToxData::VOIPToxData(void)
{


}

VOIPToxData::~VOIPToxData(void)
{
}

std::string VOIPToxData::GetSettingsFile() const
{
  string settingFile = g_strClientPath;
  if (settingFile.at(settingFile.size() - 1) == '\\' ||
      settingFile.at(settingFile.size() - 1) == '/')
    settingFile.append("VOIPToxAddonSettings.xml");
  else
    settingFile.append("/VOIPToxAddonSettings.xml");
  return settingFile;
}

VOIP_ERROR VOIPToxData::Register(ADDON_HANDLE handle, bool bRadio)
{
  

  return VOIP_ERROR_NO_ERROR;
}


VOIP_ERROR VOIPToxData::Unregister(void)
{
  
}

