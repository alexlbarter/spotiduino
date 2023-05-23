# Spotiduino
## Serial communications - v0.1
The Spotiduino Python server will send messages to the Arduino in the following format

### Format
#### **1. Beginning**
All new messages to the Arduino will begin with `$`.

#### **2. Fields**
Each message will be composed of one or more fields.
* Each field will start with `{`
* Then the name of the field will be sent, proceded by `:`
* The end of the field will be marked by `}`
```
{<name>:<data>}
```

#### **3. End**
The message will then end with `#`.

### Examples

```
${title:Good Days}#
${title:Good Days}{artist:SZA}#
${title:Good Days}{artist:SZA}{type:track}#
```