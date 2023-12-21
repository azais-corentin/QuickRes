# QuickRes

QuickRes is a small command line utility that allows the user to quickly change screen resolution and refresh rate.
It applies the changes to the main monitor as selected in windows settings.

It should work on Windows 2000 and above, but it's only being tested on Windows 11.

# Usage

```
> QuickRes.exe -w 1920 -h 1080 -r 60
```

```
Options:
  -w --width        WIDTH        Changes the screen width to WIDTH
  -h --height       HEIGHT       Changes the screen height to HEIGHT
  -r --refresh-rate REFRESH_RATE Changes the screen refresh rate to REFRESH_RATE
```