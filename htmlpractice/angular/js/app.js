var app=angular.module('basicApp',[]);
app.controller('homeController',function($scope){

    $scope.uname="DemoUser";
    $scope.testMe = function() {
            $scope.uname+="Dash";
    };
});