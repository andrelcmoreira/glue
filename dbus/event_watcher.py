from dbus import SystemBus
from dbus.mainloop.glib import DBusGMainLoop
from gi.repository import GLib

def event_handler(*args):
    print(
        'event received, sender: {}, args: {}'.format(
            args[0], args[1] if len(args) > 1 else 'None'
        )
    )

def main():
    loop = DBusGMainLoop(set_as_default=True)
    bus = SystemBus(mainloop=loop)

    bus.add_signal_receiver(event_handler)

    return GLib.MainLoop().run()

if __name__ == "__main__":
    main()
