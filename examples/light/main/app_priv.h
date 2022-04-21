/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#pragma once

#include <esp_err.h>
#include <esp_matter.h>

/** Standard max values (used for remapping attributes) */
#define STANDARD_BRIGHTNESS 100
#define STANDARD_HUE 360
#define STANDARD_SATURATION 100

/** Matter max values (used for remapping attributes) */
#define MATTER_BRIGHTNESS 254
#define MATTER_HUE 255
#define MATTER_SATURATION 255

/** Default attribute values used during initialization */
#define DEFAULT_POWER true
#define DEFAULT_BRIGHTNESS 64
#define DEFAULT_HUE 128
#define DEFAULT_SATURATION 255

/** Initialize the board and the drivers
 *
 * This initializes the selected board, which then initializes the respective drivers associated with it.
 *
 * @return ESP_OK on success.
 * @return error in case of failure.
 */
esp_err_t app_driver_init(void);

/** Driver Update
 *
 * This API should be called to update the driver for the attribute being updated.
 * This is usually called from the common `app_attribute_update_cb()`.
 *
 * @param[in] endpoint_id Endpoint ID of the attribute.
 * @param[in] cluster_id Cluster ID of the attribute.
 * @param[in] attribute_id Attribute ID of the attribute.
 * @param[in] val Pointer to `esp_matter_attr_val_t`. Use appropriate elements as per the value type.
 *
 * @return ESP_OK on success.
 * @return error in case of failure.
 */
esp_err_t app_driver_attribute_update(int endpoint_id, int cluster_id, int attribute_id, esp_matter_attr_val_t *val);
