/******************************************************************************
 Copyright (C) 2014 by John R. Bradley <jrb@turrettech.com>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

#pragma once

#include <include/cef_client.h>

class BrowserSource;
class BrowserRenderHandler;

class BrowserClient : public CefClient, public CefLifeSpanHandler,
		public CefContextMenuHandler
{
public:
	BrowserClient(CefRenderHandler *renderHandler);

public: /* CefClient overrides */
	virtual CefRefPtr<CefRenderHandler> GetRenderHandler() OVERRIDE;
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE;
	virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler()
			OVERRIDE;

public: /* CefLifeSpanHandler overrides */
	virtual bool OnBeforePopup(CefRefPtr<CefBrowser> browser,
			CefRefPtr<CefFrame> frame, const CefString& target_url,
			const CefString& target_frame_name,
			const CefPopupFeatures& popupFeatures,
			CefWindowInfo& windowInfo, CefRefPtr<CefClient>& client,
			CefBrowserSettings& settings,
			bool* no_javascript_access) OVERRIDE;
public: /* CefContextMenuHandler overrides */
	virtual void OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
			CefRefPtr<CefFrame> frame,
			CefRefPtr<CefContextMenuParams> params,
			CefRefPtr<CefMenuModel> model);
private:
	CefRefPtr<CefRenderHandler> renderHandler;

public:
	IMPLEMENT_REFCOUNTING(BrowserClient);
};