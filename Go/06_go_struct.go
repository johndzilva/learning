package main

import "fmt"

const cons_val float64 = 1.64

type car struct {
	brake_sensor      uint16
	accelerator_value uint16
	horn_value        bool
	gas_meter         float64
}

func (c car) value_conv() float64 {
	return float64(c.accelerator_value) * cons_val
}

func (c *car) pointer_conv(some_value uint16) float64 {
	c.accelerator_value = some_value
	return float64(c.accelerator_value) * 10
}

func value_assign(c car, some_value uint16) car {
	c.accelerator_value = some_value
	return c
}

func main() {
	a_car := car{
		brake_sensor:      22,
		accelerator_value: 33,
		horn_value:        true,
		gas_meter:         12.12}
	fmt.Println("brake sensor value", a_car.brake_sensor)
	fmt.Println("After conversion ", a_car.value_conv())
	fmt.Println("Pointer conversion function ", a_car.pointer_conv(100))
	a_car = value_assign(a_car, 200)
	fmt.Println("Value after assign ", a_car.accelerator_value)
}
