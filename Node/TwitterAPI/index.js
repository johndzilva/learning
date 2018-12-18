var cloudinary = require('cloudinary');
var unirest = require('unirest');
var wrap = require('word-wrap');
var random_name = require('node-random-name');
var schedule = require('node-schedule');
var request = require('request').defaults({encoding: 'base64'});
const Twit = require('twit');

var rootCas = require('ssl-root-cas/latest').create();

require('https').globalAgent.options.ca = rootCas;

var imgapi = 'https://picsum.photos/1920/1280/?random';
var imgname = random_name({first: true, gender: "female"});
var status = '#DailyQuote #DailyVibes #MorningVibes #MotivationalQuotes #dontgiveup #quotes';

cloudinary.config({
    cloud_name: 'twitterapi',
    api_key: '796173773422684',
    api_secret: 'Q-n1O6tIWCA7DQbPJ-IJFN_3SS0'
});

const T = new Twit({
    consumer_key: 'Hr9PUI7AQF3l0n7O97XsuMVNP',
    consumer_secret: 'jE8WsFOftxDokQAK4ZD6FYV9wSOoK5nQLVjl0EIh2TZIp8IYdJ',
    access_token: '1065315827069575168-1mquMN9qu98QFwkwej9l8DTOkenvEP',
    access_token_secret: '1bvET2bwqnWWdJ0H5zufer7f32yhKc6ys0A6pVdsH8DwN',
    timeout_ms: 60 * 1000,
});

// this is to call a function at definite interval
// var status = schedule.scheduleJob('*/1 * * * *', function(){
//     uploadimage();
//     getquote();
// });
//
uploadimage();
getquote();

function uploadimage() {
    cloudinary.v2.uploader.upload(
        imgapi,
        {
            public_id: imgname,
            width: 1920,
            height: 1280,
            tags: ['special', 'overlay']
        },
        function (error, result) {
        });
}

function getquote() {
    unirest.post("https://andruxnet-random-famous-quotes.p.mashape.com/?cat=famous&count=1")
        .header("X-Mashape-Key", "PFER1WW8brmshUiH1WOhiCary4uop1sxYyQjsnzF7Y00mVqwc3")
        .header("Content-Type", "application/x-www-form-urlencoded")
        .header("Accept", "application/json")
        .end(function (result) {
            var messageContent = JSON.parse(JSON.stringify(result.body));
            transform(messageContent[0]);
        });
}

function transform(tag) {
    var str = wrap(tag.quote, {width: 60});
    str = str + "\n - " + tag.author;
    var temp = cloudinary.image(imgname.toString(), {
        transformation: [
            {overlay: "black", width: "1.0", height: "0.3", flags: "relative", opacity: 60},
            {
                overlay: {font_family: "Arial", width: "0.5", font_size: 50, font_weight: "bold", text: str},
                color: "white"
            }
        ]
    });

    // this expression is to take out the image url from the img tag
    var myRegex = /<img[^>]+src='(http:\/\/[^">]+)'/g;
    var imagelink = myRegex.exec(temp);

    request.get(imagelink[1], function (error, response, body) {
        if (!error && response.statusCode == 200) {
            upload_random_image(body, tag.author);
        }
    });
}

function upload_random_image(image, author) {
    console.log('Opening an image...');

    T.post('media/upload', {media_data: image}, function (err, data, response) {
        if (err) {
            console.log('ERROR:');
            console.log(err);
        }
        else {
            T.post('statuses/update', {
                    status: status + ' - ' + author,
                    media_ids: new Array(data.media_id_string)
                },
                function (err, data, response) {
                    if (err) {
                        console.log('ERROR:');
                        console.log(err);
                    }
                    else {
                        console.log('Posted an image!');
                    }
                }
            );
        }
    });
}