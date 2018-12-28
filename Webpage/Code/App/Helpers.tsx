import React from "react"

export const Loading: React.FunctionComponent = () => (
    <div className="preloader-wrapper big active" style={{width: "100%"}}>
        <br />
        <br />
        
        <div className="spinner-layer spinner-blue">
            
            <div className="circle-clipper left">
                <div className="circle" />
            </div>

            <div className="gap-patch">
                <div className="circle" />
            </div>
            
            <div className="circle-clipper right">
                <div className="circle" />
            </div>

        </div>

        <br />
        <br />
    </div>
)


export const ErrorMessage: React.FunctionComponent = () => (
    <div className="container">
        <div className="row">
            <div className="col s12">
                <div className="card-panel">
                    
                    <div className="center">
                        <h4 className="blue-grey-text text-darken-3">
                            Error, Something did not go right. Sorry :(
                        </h4>
                        <br />
                        <br />
                    </div>

                </div>
            </div>
        </div>

        <br /><br /><br /><br />
        <br /><br /><br /><br />
        <br /><br /><br /><br />
        <br /><br /><br /><br />
        <br /><br /><br /><br />

    </div>
)
