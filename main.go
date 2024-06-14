package main

import (
	"fmt"
	"reflect"

	"github.com/bitly/go-simplejson"
)

type P struct {
	X int `json:"x"`
	Y int `json:"y"`
}

func CreateSimpleJSON(data any) *simplejson.Json {
	ret := simplejson.New()
	// data是切片，需要特殊处理
	if reflect.TypeOf(data).Kind() == reflect.Slice {
		retArray := make([]any, 0)
		sliceValue := reflect.ValueOf(data)
		for i := 0; i < sliceValue.Len(); i++ {
			element := sliceValue.Index(i).Interface()
			// 将切片中的每个元素添加到 JSON 数组中
			retArray = append(retArray, element)
		}
		ret.SetPath([]string{}, retArray)
	} else {
		ret.SetPath([]string{}, data)
	}

	return ret
}

func main() {
	a := make([]P, 0)
	a = append(a, P{
		X: 1,
		Y: 1,
	})
	a = append(a, P{
		X: 2,
		Y: 2,
	})

	jsonData := CreateSimpleJSON(a)
	poi := jsonData.GetIndex(0)

	// 获取 poi 中 x 的值
	xValue, err := poi.Get("x").Int()
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Println("x:", xValue)
	}
}
