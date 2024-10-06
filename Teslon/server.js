const express = require("express")
const app = express()
const port = 3000
const { exec } = require('node:child_process')


app.use(
  express.urlencoded({extended: true,})
)


app.get("/", (req, res) => {
  res.sendFile(__dirname + "/index.html")
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})

var n = 0;

app.post("/", async (req, res) => {
        const what = await req.body.controll
        console.log(what)
        console.log(n);
        n += 1;

        if(what == "forward" && n == 1){
                exec('sudo ./Forward', (err, output) => {
                        if (err) {
                                console.error("could not execute command: ", err)
                                return
                        }
                })
        }


        if(what == "backward" && n == 1){
                exec('sudo ./Backward', (err, output) => {
                        if (err) {
                                console.error("could not execute command: ", err)
                                return
                        }
                })
        }


        if(what == "left" && n == 1){
                exec('sudo ./Left', (err, output) => {
                        if (err) {
                                console.error("could not execute command: ", err)
                                return
                        }
                })
        }


        if(what == "right" && n == 1){
                exec('sudo ./Right', (err, output) => {
                        if (err) {
                                console.error("could not execute command: ", err)
                                return
                        }
                })
        }


        if(n == 2){
                exec('sudo ./Off', (err, output) => {
                        n = 0;
                        if(err){
                                console.error("error while exec", err)
                                return
                        }
                })
        }
})
