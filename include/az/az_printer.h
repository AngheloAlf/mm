#ifndef AZ_PRINTER_H
#define AZ_PRINTER_H


#define AZ_PRINTER __az_printer

#define AZ_OPEN_PRINTER_OVERLAY() \
    { \
        GfxPrint AZ_PRINTER; \
        Gfx* __az_gfxRef; \
        Gfx* __az_gfx; \
         \
        GfxPrint_Init(&AZ_PRINTER); \
         \
        __az_gfxRef = POLY_OPA_DISP; \
        __az_gfx = Graph_GfxPlusOne(__az_gfxRef); \
        gSPDisplayList(OVERLAY_DISP++, __az_gfx); \
         \
        GfxPrint_Open(&AZ_PRINTER, __az_gfx)


#define AZ_CLOSE_PRINTER_OVERLAY() \
        __az_gfx = GfxPrint_Close(&AZ_PRINTER); \
         \
        gSPEndDisplayList(__az_gfx++); \
        Graph_BranchDlist(__az_gfxRef, __az_gfx); \
        POLY_OPA_DISP = __az_gfx; \
         \
        GfxPrint_Destroy(&AZ_PRINTER); \
    } \
    (void)0

#endif
