#ifndef __NEXTEXT_H__
#define __NEXTEXT_H__
#include "NexTouch.h"
#include "NexHardware.h"
#include "../util/Utilities.h"
/**
     * Get text attribute of component.
     *
     * @param buffer - buffer storing text returned. 
     * @param len - length of buffer. 
     * @return The real length of text returned. 
     */
uint16_t NexText_getText(struct NexObject *text, char *buffer, uint16_t len);

/**
     * Set text attribute of component.
     *
     * @param buffer - text buffer terminated with '\0'. 
     * @return true if success, false for failure. 
     */
uint8_t NexText_setText(struct NexObject *text, char *buffer);

/**
     * Get bco attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexText_Get_background_color_bco(struct NexObject *text, uint32_t *number);

/**
     * Set bco attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexText_Set_background_color_bco(struct NexObject *text, uint32_t number);

/**
     * Get pco attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexText_Get_font_color_pco(struct NexObject *text, uint32_t *number);

/**
     * Set pco attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexText_Set_font_color_pco(struct NexObject *text, uint32_t number);

/**
     * Get xcen attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexText_Get_place_xcen(struct NexObject *text, uint32_t *number);

/**
     * Set xcen attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexText_Set_place_xcen(struct NexObject *text, uint32_t number);

/**
     * Get ycen attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexText_Get_place_ycen(struct NexObject *text, uint32_t *number);

/**
     * Set ycen attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexText_Set_place_ycen(struct NexObject *text, uint32_t number);

/**
     * Get font attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexText_getFont(struct NexObject *text, uint32_t *number);

/**
     * Set font attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexText_setFont(struct NexObject *text, uint32_t number);

/**
     * Get picc attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexText_Get_background_crop_picc(struct NexObject *text, uint32_t *number);

/**
     * Set picc attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexText_Set_background_crop_picc(struct NexObject *text, uint32_t number);

/**
     * Get pic attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexText_Get_background_image_pic(struct NexObject *text, uint32_t *number);

/**
     * Set pic attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexText_Set_background_image_pic(struct NexObject *text, uint32_t number);

#endif /* #ifndef __NEXTEXT_H__ */