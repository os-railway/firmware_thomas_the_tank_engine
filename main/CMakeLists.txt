idf_component_register(SRCS "main.c" "osr_ble.c"
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES 
                        nvs_flash)
