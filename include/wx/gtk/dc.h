/////////////////////////////////////////////////////////////////////////////
// Name:        wx/gtk/dc.h
// Purpose:
// Author:      Robert Roebling
// Id:          $Id$
// Copyright:   (c) 1998 Robert Roebling
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef __GTKDCH__
#define __GTKDCH__


//-----------------------------------------------------------------------------
// wxDC
//-----------------------------------------------------------------------------

#if wxUSE_NEW_DC
class WXDLLIMPEXP_CORE wxGTKImplDC : public wxImplDC
#else
#define wxGTKImplDC wxDC
class WXDLLIMPEXP_CORE wxDC : public wxDCBase
#endif

{
public:
#if wxUSE_NEW_DC
    wxGTKImplDC( wxDC *owner );
#else
    wxDC();
#endif

    virtual ~wxGTKImplDC();

#if wxUSE_PALETTE
    void SetColourMap( const wxPalette& palette ) { SetPalette(palette); };
#endif // wxUSE_PALETTE

    // Resolution in pixels per logical inch
    virtual wxSize GetPPI() const;

    virtual bool StartDoc( const wxString& WXUNUSED(message) ) { return true; }
    virtual void EndDoc() { }
    virtual void StartPage() { }
    virtual void EndPage() { }

    virtual GdkWindow* GetGDKWindow() const { return NULL; }

protected:
    // base class pure virtuals implemented here
    virtual void DoSetClippingRegion(wxCoord x, wxCoord y, wxCoord width, wxCoord height);
    virtual void DoGetSizeMM(int* width, int* height) const;

private:
    DECLARE_ABSTRACT_CLASS(wxGTKImplDC)
};

// this must be defined when wxDC::Blit() honours the DC origian and needed to
// allow wxUniv code in univ/winuniv.cpp to work with versions of wxGTK
// 2.3.[23]
#ifndef wxHAS_WORKING_GTK_DC_BLIT
    #define wxHAS_WORKING_GTK_DC_BLIT
#endif

#endif // __GTKDCH__
