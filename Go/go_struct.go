package main

import "fmt"

type car struct {
	brake_sensor      uint16
	accelerator_value uint16
	horn_value        bool
	gas_meter         float64
}

func main() {
	a_car := car{
		brake_sensor:      22,
		accelerator_value: 33,
		horn_value:        true,
		gas_meter:         12.12}
	fmt.Println("brake sensor value", a_car.brake_sensor)
}
