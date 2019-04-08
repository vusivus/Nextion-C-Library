#ifndef __NEXNUMBER_H__
#define __NEXNUMBER_H__

#include "NexTouch.h"
#include "NexHardware.h"

/**
     * Get number attribute of component.
     *
     * @param number - buffer storing text returned. 
     * @return The real length of text returned. 
     */
uint8_t NexNumber_getValue(struct NexObject *number, uint32_t *num);

/**
     * Set number attribute of component.
     *
     * @param number - number buffer. 
     * @return true if success, false for failure. 
     */
uint8_t NexNumber_setValue(struct NexObject *number, uint32_t num);

/**
     * Get bco attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexNumber_Get_background_color_bco(struct NexObject *number, uint32_t *num);

/**
     * Set bco attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexNumber_Set_background_color_bco(struct NexObject *number, uint32_t num);

/**
     * Get pco attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexNumber_Get_font_color_pco(struct NexObject *number, uint32_t *num);

/**
     * Set pco attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexNumber_Set_font_color_pco(struct NexObject *number, uint32_t num);

/**
     * Get xcen attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexNumber_Get_place_xcen(struct NexObject *number, uint32_t *num);

/**
     * Set xcen attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexNumber_Set_place_xcen(struct NexObject *number, uint32_t num);

/**
     * Get ycen attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexNumber_Get_place_ycen(struct NexObject *number, uint32_t *num);

/**
     * Set ycen attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexNumber_Set_place_ycen(struct NexObject *number, uint32_t num);

/**
     * Get font attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexNumber_getFont(struct NexObject *number, uint32_t *num);

/**
     * Set font attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexNumber_setFont(struct NexObject *number, uint32_t num);

/**
     * Get lenth attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexNumber_Get_number_lenth(struct NexObject *number, uint32_t *num);

/**
     * Set lenth attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexNumber_Set_number_lenth(struct NexObject *number, uint32_t num);

/**
     * Get picc attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexNumber_Get_background_crop_picc(struct NexObject *number, uint32_t *num);

/**
     * Set picc attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexNumber_Set_background_crop_picc(struct NexObject *number, uint32_t num);

/**
     * Get pic attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
uint32_t NexNumber_Get_background_image_pic(struct NexObject *number, uint32_t *num);

/**
     * Set pic attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
uint8_t NexNumber_Set_background_image_pic(struct NexObject *number, uint32_t num);

#endif /* #ifndef __NEXNUMBER_H__ */