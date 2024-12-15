Creating a **REST API** with **AWS Lambda** and **DynamoDB** using the **Serverless Framework** is a common and powerful use case for building scalable, serverless applications. The Serverless Framework makes it easy to define and deploy the infrastructure, including Lambda functions, API Gateway endpoints, and DynamoDB tables, with minimal code.

Here's a step-by-step guide to create a REST API with DynamoDB using the **Serverless Framework**:

### Steps to Create a REST API with Lambda and DynamoDB

#### 1. **Set Up the Serverless Project**

Start by creating a new Serverless service/project if you haven’t already. You can use the following command to generate a basic service:

```bash
serverless create --template aws-nodejs --path my-api
cd my-api
```

#### 2. **Install Dependencies**

You'll need the **AWS SDK** for DynamoDB (which is included by default in Lambda environments), but you may also want to install additional packages (like a body parser or API validation library) for your API.

For now, we'll use the built-in DynamoDB SDK.

#### 3. **Define DynamoDB Table in `serverless.yml`**

In the `serverless.yml` file, define the DynamoDB table that you will use to store the data. You can do this under the `resources` section. Here’s an example of creating a `Users` table with `userId` as the partition key.

```yaml
service: rest-api-with-dynamodb

provider:
  name: aws
  runtime: nodejs14.x

functions:
  createUser:
    handler: handler.createUser
    events:
      - http:
          path: users
          method: post
          cors: true  # Enable CORS
          
  getUser:
    handler: handler.getUser
    events:
      - http:
          path: users/{userId}
          method: get
          cors: true  # Enable CORS

resources:
  Resources:
    UsersTable:
      Type: AWS::DynamoDB::Table
      Properties:
        TableName: Users
        AttributeDefinitions:
          - AttributeName: userId
            AttributeType: S
        KeySchema:
          - AttributeName: userId
            KeyType: HASH
        ProvisionedThroughput:
          ReadCapacityUnits: 5
          WriteCapacityUnits: 5
```

In this example:
- **UsersTable**: This DynamoDB table has a `userId` as the partition key (`HASH` key).
- **createUser** and **getUser**: Two Lambda functions are created — one for creating users (`POST /users`) and one for retrieving users (`GET /users/{userId}`).
- **ProvisionedThroughput**: Sets the read and write capacity for DynamoDB (you can switch to `OnDemand` mode for automatic scaling).

#### 4. **Write Lambda Functions**

Now, create the Lambda functions that will handle the API requests.

1. **Create a new file `handler.js`** in your project directory.
2. Implement the functions for creating and getting a user.

Here’s an example of how you can implement these functions:

```javascript
const AWS = require('aws-sdk');
const dynamoDb = new AWS.DynamoDB.DocumentClient();

module.exports.createUser = async (event) => {
  const { userId, name, email } = JSON.parse(event.body);

  const params = {
    TableName: 'Users',
    Item: {
      userId,
      name,
      email,
    },
  };

  try {
    await dynamoDb.put(params).promise();

    return {
      statusCode: 201,
      body: JSON.stringify({ message: 'User created successfully!' }),
    };
  } catch (error) {
    console.error(error);
    return {
      statusCode: 500,
      body: JSON.stringify({ message: 'Failed to create user' }),
    };
  }
};

module.exports.getUser = async (event) => {
  const { userId } = event.pathParameters;

  const params = {
    TableName: 'Users',
    Key: {
      userId,
    },
  };

  try {
    const result = await dynamoDb.get(params).promise();

    if (!result.Item) {
      return {
        statusCode: 404,
        body: JSON.stringify({ message: 'User not found' }),
      };
    }

    return {
      statusCode: 200,
      body: JSON.stringify(result.Item),
    };
  } catch (error) {
    console.error(error);
    return {
      statusCode: 500,
      body: JSON.stringify({ message: 'Failed to get user' }),
    };
  }
};
```

In the code:
- **createUser**: This function parses the incoming JSON body, constructs a DynamoDB `put` operation, and stores the user data in the `Users` table.
- **getUser**: This function retrieves the user by `userId` from DynamoDB using the `get` operation. It returns a 404 error if the user is not found.

#### 5. **Deploy the Service**

Deploy your service using the following command:

```bash
serverless deploy
```

This will deploy the Lambda functions, API Gateway, and DynamoDB table to AWS. It will also provide you with the API Gateway URL for your REST API.

#### 6. **Test the API**

Once the deployment is successful, you’ll receive the URL to your REST API in the output. You can use tools like **Postman** or **cURL** to test the API.

For example, to create a user, you can send a `POST` request to the API Gateway endpoint (replace `<api-url>` with the actual URL from the deployment output):

```bash
curl -X POST <api-url>/users \
  -H "Content-Type: application/json" \
  -d '{"userId": "123", "name": "John Doe", "email": "john.doe@example.com"}'
```

To get a user, send a `GET` request to:

```bash
curl <api-url>/users/123
```

---

### 7. **Managing API Security and Permissions**

By default, the API is publicly accessible. If you want to restrict access (for example, using API keys, IAM roles, or AWS Cognito), you can configure API Gateway's authorization methods in `serverless.yml`. You can also implement AWS IAM policies to control access to DynamoDB.

Here’s how to add **IAM permissions** to allow Lambda functions to access DynamoDB:

```yaml
functions:
  createUser:
    handler: handler.createUser
    events:
      - http:
          path: users
          method: post
          cors: true
    iamRoleStatements:
      - Effect: Allow
        Action:
          - dynamodb:PutItem
        Resource:
          - arn:aws:dynamodb:${self:provider.region}:*:table/Users

  getUser:
    handler: handler.getUser
    events:
      - http:
          path: users/{userId}
          method: get
          cors: true
    iamRoleStatements:
      - Effect: Allow
        Action:
          - dynamodb:GetItem
        Resource:
          - arn:aws:dynamodb:${self:provider.region}:*:table/Users
```

This ensures that the Lambda functions have the correct IAM permissions to interact with DynamoDB.

---

### Conclusion

With the **Serverless Framework**, you can quickly build a REST API powered by **AWS Lambda** and **DynamoDB**. By defining the API routes, Lambda functions, and DynamoDB tables in the `serverless.yml` file, you can easily deploy, manage, and scale your API. The Serverless Framework abstracts much of the infrastructure management, so you can focus more on building the logic of your application.

