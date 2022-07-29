add_library(orderbook SHARED
    orderbook.cpp
    ordermap.cpp
    LimitPrice.cpp
    OrderEntry.cpp
)

add_library(orderentry SHARED
    OrderEntry.cpp
)

add_library(ordermap SHARED
    ordermap.cpp
    LimitPrice.cpp
    OrderEntry.cpp
)

add_library(limitprice SHARED
    LimitPrice.cpp
)