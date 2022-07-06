from dbus import SystemBus, Interface

def dbus_func(func):
    def f(*args):
        print(func.__name__)
        print('=' * 80)
        func(*args)
        print('=' * 80)
        print('')

    return f

@dbus_func
def print_devices(obj_iface):
    for dev in obj_iface.GetDevices():
        print(dev)

@dbus_func
def print_devices_info(bus, obj_iface):
    for dev in obj_iface.GetDevices():
        proxy = bus.get_object("org.freedesktop.NetworkManager", dev)

        prop_iface = Interface(proxy, "org.freedesktop.DBus.Properties")
        props = prop_iface.GetAll("org.freedesktop.NetworkManager.Device")

        print(props)

@dbus_func
def print_device_info(bus, obj_iface, net_iface):
    path = obj_iface.GetDeviceByIpIface(net_iface)

    proxy = bus.get_object(
        "org.freedesktop.NetworkManager", # service
        path # object
    )

    # Get the service interface
    prop_iface = Interface(proxy, "org.freedesktop.DBus.Properties")
    props = prop_iface.GetAll("org.freedesktop.NetworkManager.Device")

    for k,v in props.items():
        print('%s: %s' % (k, v))

@dbus_func
def print_state(obj_iface):
    print('network state:', obj_iface.state())

@dbus_func
def print_connectivity_state(obj_iface):
    print('connectivity state:', obj_iface.CheckConnectivity())

@dbus_func
def print_device_path(obj_iface, net_iface):
    print(
        'path for %s: %s' % (net_iface, obj_iface.GetDeviceByIpIface(net_iface))
    )

@dbus_func
def list_services(bus):
    for sv in bus.list_names():
        print(sv)

def main():
    bus = SystemBus()
    proxy = bus.get_object(
        "org.freedesktop.NetworkManager", # service
        "/org/freedesktop/NetworkManager" # object path
    )

    # Get the object interface
    obj_iface = Interface(proxy, "org.freedesktop.NetworkManager")

    list_services(bus)
    print_devices(obj_iface)
    print_devices_info(bus, obj_iface)
    print_state(obj_iface)
    print_connectivity_state(obj_iface)
    print_device_path(obj_iface, 'wlo1')
    print_device_path(obj_iface, 'enp3s0')
    print_device_info(bus, obj_iface, 'wlo1')
    print_device_info(bus, obj_iface, 'enp3s0')

if __name__ == "__main__":
    main()
